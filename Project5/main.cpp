/**
* Author: Belinda Weng
* Assignment: your house
* Date due: 5/2/2025, 2:00pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

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
#include "MenuScene.h"
#include "LevelA.h"
#include "LevelB.h"
#include "LevelC.h"
#include "LoseScene.h"
#include "WinScene.h"

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

constexpr char GAME_WINDOW_NAME[] = "your house";

constexpr char V_SHADER_PATH[] = "shaders/vertex_textured.glsl",
F_SHADER_PATH[] = "shaders/fragment_textured.glsl";

constexpr float MILLISECONDS_IN_SECOND = 1000.0;

// Path to the background music
constexpr char BGM_FILEPATH[] = "assets/audio/Penumbra.wav";

constexpr char WOOD_FILEPATH[] = "assets/audio/wood.wav";

enum AppStatus { RUNNING, TERMINATED };
enum GameMode { MENU_SCENE, LEVEL_A, LEVEL_B, LEVEL_C, LOSE_SCENE, WIN_SCENE };

// ————— VARIABLES ————— //
Scene* g_current_scene;
MenuScene* g_menu_scene;
LevelA* g_level_a;
LevelB* g_level_b;
LevelC* g_level_c;
LoseScene* g_lose_scene;
WinScene* g_win_scene;
GameMode g_current_mode = MENU_SCENE; // Start with menu scene
GameMode g_previous_mode = MENU_SCENE;

// Global music variable
Mix_Music* g_game_music = nullptr;
Mix_Music* footsteps = nullptr;

// Track if the player has collected the final key
bool g_has_final_key = false;

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

    // ————— AUDIO SETUP ————— //
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    g_game_music = Mix_LoadMUS(BGM_FILEPATH);
    if (g_game_music == nullptr) {
        LOG("ERROR: Could not load background music.\n");
    }
    else {
        Mix_PlayMusic(g_game_music, -1);
        Mix_VolumeMusic(60); 
    }

    footsteps = Mix_LoadMUS(WOOD_FILEPATH);

    // ————— VIDEO SETUP ————— //
    glViewport(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);

    g_shader_program.load(V_SHADER_PATH, F_SHADER_PATH);

    g_view_matrix = glm::mat4(1.0f);
    g_projection_matrix = glm::ortho(-8.0f, 8.0f, -6.0f, 6.0f, -1.0f, 1.0f);

    g_shader_program.set_projection_matrix(g_projection_matrix);
    g_shader_program.set_view_matrix(g_view_matrix);

    glUseProgram(g_shader_program.get_program_id());

    glClearColor(BG_RED, BG_BLUE, BG_GREEN, BG_OPACITY);

    // Initialize our scenes
    g_menu_scene = new MenuScene();
    g_menu_scene->initialise();

    g_level_a = new LevelA();
    g_level_b = new LevelB();
    g_level_c = new LevelC();
    g_lose_scene = new LoseScene();
    g_lose_scene->initialise();
    g_win_scene = new WinScene();
    g_win_scene->initialise();

    // Set the current scene to menu scene
    g_current_scene = g_menu_scene;

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
                g_previous_mode = g_current_mode;
                g_current_mode = LEVEL_A;
                g_current_scene = g_level_a;
                g_current_scene->initialise();
                break;

            case SDLK_2:
                // Switch to Level B
                g_previous_mode = g_current_mode;
                g_current_mode = LEVEL_B;
                g_current_scene = g_level_b;
                g_current_scene->initialise();
                break;

            case SDLK_3:
                g_previous_mode = g_current_mode;
                g_current_mode = LEVEL_C;
                g_current_scene = g_level_c;
                g_current_scene->initialise();
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
    if (g_current_mode == MENU_SCENE) {
        g_menu_scene->process_input();
    }
    else if (g_current_mode == LEVEL_A) {
        g_level_a->process_input();
    }
    else if (g_current_mode == LEVEL_B) {
        g_level_b->process_input();
    }
    else if (g_current_mode == LEVEL_C) {
        g_level_c->process_input();
    }

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

    // Check if the player has collected the final key in Level C
    if (g_current_mode == LEVEL_C) {
        LevelC* level_c = dynamic_cast<LevelC*>(g_current_scene);
        if (level_c && level_c->get_key_collected()) {
            g_has_final_key = true;
        }
    }

    int next_scene = g_current_scene->get_state().next_scene_id;
    GameMode current_mode = g_current_mode;

    // Check if we need to switch scenes
    if (next_scene == 0 && g_current_mode != LEVEL_A) {
        // Switch to Level A
        g_previous_mode = g_current_mode;
        g_current_mode = LEVEL_A;
        g_current_scene = g_level_a;

        // Only initialize if coming from menu scene, otherwise use existing state
        if (g_previous_mode == MENU_SCENE) {
            g_current_scene->initialise();
        }
        else {
            // Backtrack to Level A
            g_level_a->get_state().player->set_position(glm::vec3(7.0f, -2.0f, 0.0f));

            // Transfer enemy state from previous level
            if (g_previous_mode == LEVEL_B && g_level_b->get_enemy_active()) {
                g_level_a->set_enemy_active(true);
                g_level_a->set_enemy_entry_position(glm::vec3(7.0f, -2.0f, 0.0f));
                g_level_a->set_enemy_timer(1.0f);
                g_level_a->set_enemy_following(false); // Will start following after timer
            }
        }

        g_level_a->get_state().next_scene_id = -1;
    }
    else if (next_scene == 1 && g_current_mode != LEVEL_B) {
        // Transition to Level B (from either A or C)
        g_previous_mode = g_current_mode;
        g_current_mode = LEVEL_B;
        g_current_scene = g_level_b;
        g_current_scene->initialise();

        glm::vec3 entry_position;

        // Set player position based on which level we came from
        if (g_previous_mode == LEVEL_C) {
            // Coming from Level C, place player at top of Level B
            entry_position = glm::vec3(3.0f, -2.0f, 0.0f);
            g_level_b->get_state().player->set_position(entry_position);

            // Transfer enemy state from Level C
            if (g_level_c->get_enemy_active()) {
                g_level_b->set_enemy_active(true);
                g_level_b->set_enemy_entry_position(entry_position);
                g_level_b->set_enemy_timer(1.0f);
                g_level_b->set_enemy_following(false); // Will start following after timer
            }
        }
        else {
            // Coming from Level A, place player at bottom of Level B
            entry_position = glm::vec3(17.0f, -12.0f, 0.0f);
            g_level_b->get_state().player->set_position(entry_position);

            // Transfer enemy state from Level A
            if (g_level_a->get_enemy_active()) {
                g_level_b->set_enemy_active(true);
                g_level_b->set_enemy_entry_position(entry_position);
                g_level_b->set_enemy_timer(1.0f);
                g_level_b->set_enemy_following(false); // Will start following after timer
            }
        }

        g_level_b->get_state().next_scene_id = -1;
    }
    else if (next_scene == 3 && g_current_mode != LEVEL_C) {
        // Switch to level C when next_scene_id is 3
        g_previous_mode = g_current_mode;
        g_current_mode = LEVEL_C;
        g_current_scene = g_level_c;
        g_current_scene->initialise(); // Initialize level C

        // Set player position at bottom of Level C
        glm::vec3 entry_position = glm::vec3(9.0f, -12.0f, 0.0f);
        g_level_c->get_state().player->set_position(entry_position);

        // Transfer enemy state from Level B
        if (g_level_b->get_enemy_active()) {
            g_level_c->set_enemy_active(true);
            g_level_c->set_enemy_timer(1.0f);
            g_level_c->set_enemy_following(false); // Will start following after timer
        }

        g_level_c->get_state().next_scene_id = -1;
    }
    else if (next_scene == 2 && g_current_mode != LOSE_SCENE) {
        // Switch to lose
        g_previous_mode = g_current_mode;
        g_current_mode = LOSE_SCENE;
        g_current_scene = g_lose_scene;
    }
    else if (next_scene == 4 && g_current_mode != WIN_SCENE) {
        // Switch to win 
        g_previous_mode = g_current_mode;
        g_current_mode = WIN_SCENE;
        g_current_scene = g_win_scene;
    }

    // Update camera to follow player
    if (g_current_mode != MENU_SCENE && g_current_mode != LOSE_SCENE && g_current_mode != WIN_SCENE) {
        GameState state = g_current_scene->get_state();
        g_view_matrix = glm::mat4(1.0f);
        g_view_matrix = glm::translate(g_view_matrix, glm::vec3(
            -state.player->get_position().x,
            -state.player->get_position().y,
            0.0f));
    }
    else {
        g_view_matrix = glm::mat4(1.0f);
    }
}

void render()
{
    g_shader_program.set_view_matrix(g_view_matrix);
    glClear(GL_COLOR_BUFFER_BIT);


    // Set light position to player position in world space
    if (g_current_mode != MENU_SCENE && g_current_mode != LOSE_SCENE && g_current_mode != WIN_SCENE) {
        g_shader_program.set_light_position(g_current_scene->get_state().player->get_position().x, g_current_scene->get_state().player->get_position().y, g_current_scene->get_state().player->get_position().z);

    }

    // Render current scene
    g_current_scene->render(&g_shader_program);

    SDL_GL_SwapWindow(g_display_window);
}

void shutdown()
{
    // Free the music resource
    if (g_game_music != nullptr) {
        Mix_FreeMusic(g_game_music);
    }

    // Close the audio system
    Mix_CloseAudio();

    SDL_Quit();

    // Clean up game state
    delete g_menu_scene;
    delete g_level_a;
    delete g_level_b;
    delete g_level_c;
    delete g_lose_scene;
    delete g_win_scene;
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
