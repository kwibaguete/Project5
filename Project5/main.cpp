#define GL_SILENCE_DEPRECATION
#define STB_IMAGE_IMPLEMENTATION
#define LOG(argument) std::cout << argument << '\n'
#define GL_GLEXT_PROTOTYPES 1
#define FIXED_TIMESTEP 0.0166666f

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "stb_image.h"
#include "cmath"
#include <ctime>
#include <vector>
#include <iostream> 
#include "Entity.h"
#include "Map.h"
#include "Scene.h"
#include "LevelA.h"
#include "LevelB.h"
#include "LoseScene.h" // Add LoseScene header

// ————— CONSTANTS ————— //
constexpr int WINDOW_WIDTH = 640 * 2,
WINDOW_HEIGHT = 480 * 2;

constexpr float BG_RED = 0.128f,
BG_BLUE = 0.128f,
BG_GREEN = 0.128f,
BG_OPACITY = 1.0f;

constexpr int VIEWPORT_X = 0,
VIEWPORT_Y = 0,
VIEWPORT_WIDTH = WINDOW_WIDTH,
VIEWPORT_HEIGHT = WINDOW_HEIGHT;

constexpr char GAME_WINDOW_NAME[] = "final";

constexpr char V_SHADER_PATH[] = "shaders/vertex_textured.glsl",
F_SHADER_PATH[] = "shaders/fragment_textured.glsl";

constexpr float MILLISECONDS_IN_SECOND = 1000.0;

enum AppStatus { RUNNING, TERMINATED };
enum GameMode { LEVEL_A, LEVEL_B, LOSE_SCENE }; // Add LOSE_SCENE to GameMode

// ————— VARIABLES ————— //
Scene* g_current_scene;
LevelA* g_level_a;
LevelB* g_level_b;
LoseScene* g_lose_scene; // Add LoseScene pointer
GameMode g_current_mode = LEVEL_A;

AppStatus g_app_status = RUNNING;
SDL_Window* g_display_window;
ShaderProgram g_shader_program;
glm::mat4 g_view_matrix, g_projection_matrix;

float g_previous_ticks = 0.0f,
g_accumulator = 0.0f;

void initialise();
void process_input();
void update();
void render();
void shutdown();

void initialise()
{
    // ————— GENERAL ————— //
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    g_display_window = SDL_CreateWindow(GAME_WINDOW_NAME,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(g_display_window);
    SDL_GL_MakeCurrent(g_display_window, context);
    if (context == nullptr)
    {
        LOG("ERROR: Could not create OpenGL context.\n");
        shutdown();
    }

#ifdef _WINDOWS
    glewInit();
#endif

    // ————— VIDEO SETUP ————— //
    glViewport(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);

    g_shader_program.load(V_SHADER_PATH, F_SHADER_PATH);

    g_view_matrix = glm::mat4(1.0f);
    g_projection_matrix = glm::ortho(-8.0f, 8.0f, -6.0f, 6.0f, -1.0f, 1.0f);

    g_shader_program.set_projection_matrix(g_projection_matrix);
    g_shader_program.set_view_matrix(g_view_matrix);

    glUseProgram(g_shader_program.get_program_id());

    glClearColor(BG_RED, BG_BLUE, BG_GREEN, BG_OPACITY);

    // Initialize our levels
    g_level_a = new LevelA();
    g_level_b = new LevelB();
    g_lose_scene = new LoseScene(); // Initialize LoseScene
    g_lose_scene->initialise(); // Initialize the lose scene

    // Set the current scene to level A
    g_current_scene = g_level_a;
    g_current_scene->initialise();

    // ————— BLENDING ————— //
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void process_input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            g_app_status = TERMINATED;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_q:
                // Quit the game with a keystroke
                g_app_status = TERMINATED;
                break;

            case SDLK_1:
                // Switch to Level A
                g_current_mode = LEVEL_A;
                g_current_scene = g_level_a;
                g_current_scene->initialise(); // Re-initialize the level
                break;

            case SDLK_2:
                // Switch to Level B
                g_current_mode = LEVEL_B;
                g_current_scene = g_level_b;
                g_current_scene->initialise(); // Re-initialize the level
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    // Process level-specific input
    if (g_current_mode == LEVEL_A) {
        g_level_a->process_input();
    }
    else if (g_current_mode == LEVEL_B) {
        g_level_b->process_input();
    }
    // No input processing needed for lose scene
}

void update()
{
    float ticks = (float)SDL_GetTicks() / MILLISECONDS_IN_SECOND;
    float delta_time = ticks - g_previous_ticks;
    g_previous_ticks = ticks;

    delta_time += g_accumulator;

    if (delta_time < FIXED_TIMESTEP)
    {
        g_accumulator = delta_time;
        return;
    }

    while (delta_time >= FIXED_TIMESTEP)
    {
        // Update current scene
        g_current_scene->update(FIXED_TIMESTEP);
        delta_time -= FIXED_TIMESTEP;
    }

    g_accumulator = delta_time;

    // Check if we need to switch scenes
    if (g_current_scene->get_state().next_scene_id == 1 && g_current_mode != LEVEL_B) {
        g_current_mode = LEVEL_B;
        g_current_scene = g_level_b;
        g_current_scene->initialise();
    }
    else if (g_current_scene->get_state().next_scene_id == 2 && g_current_mode != LOSE_SCENE) {
        // Switch to lose scene when next_scene_id is 2
        g_current_mode = LOSE_SCENE;
        g_current_scene = g_lose_scene;
        // No need to re-initialize the lose scene
    }

    // Update camera to follow player, but only in gameplay scenes
    if (g_current_mode != LOSE_SCENE) {
        GameState state = g_current_scene->get_state();
        g_view_matrix = glm::mat4(1.0f);
        g_view_matrix = glm::translate(g_view_matrix, glm::vec3(
            -state.player->get_position().x,
            -state.player->get_position().y,
            0.0f));
    }
    else {
        // Reset view matrix for lose scene (centered view)
        g_view_matrix = glm::mat4(1.0f);
    }
}

void render()
{
    g_shader_program.set_view_matrix(g_view_matrix);
    glClear(GL_COLOR_BUFFER_BIT);

    // Render current scene
    g_current_scene->render(&g_shader_program);

    SDL_GL_SwapWindow(g_display_window);
}

void shutdown()
{
    SDL_Quit();

    // Clean up game state
    delete g_level_a;
    delete g_level_b;
    delete g_lose_scene; 
}

// ————— GAME LOOP ————— //
int main(int argc, char* argv[])
{
    initialise();

    while (g_app_status == RUNNING)
    {
        process_input();
        update();
        render();
    }

    shutdown();
    return 0;
}
