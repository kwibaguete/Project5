#define GL_SILENCE_DEPRECATION
#define STB_IMAGE_IMPLEMENTATION
#define LOG(argument) std::cout << argument << '\n'
#define GL_GLEXT_PROTOTYPES 1
#define FIXED_TIMESTEP 0.0166666f
#define ENEMY_COUNT 1
#define LEVEL1_WIDTH 20  // Increased from 14
#define LEVEL1_HEIGHT 15 // Increased from 5

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
#include "Entity.h"
#include "Map.h"

// ————— GAME STATE ————— //
struct GameState
{
    Entity* player;
    Entity* enemies;
    Entity* key;

    bool key_spawned = false;
    bool key_collected = false;
    glm::vec3 key_position;

    // freeze effect
    bool game_frozen = false;
    float freeze_timer = 0.0f;
    const float FREEZE_DURATION = 0.5f;

    Map* map;
    Map* background_map;

    Mix_Music* bgm;
    Mix_Chunk* jump_sfx;
};

enum AppStatus { RUNNING, TERMINATED };

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

constexpr char GAME_WINDOW_NAME[] = "Hello, Maps!";

constexpr char V_SHADER_PATH[] = "shaders/vertex_textured.glsl",
F_SHADER_PATH[] = "shaders/fragment_textured.glsl";

constexpr float MILLISECONDS_IN_SECOND = 1000.0;

constexpr char SPRITESHEET_FILEPATH[] = "assets/player.png",
//MAP_TILESET_FILEPATH[] = "assets/images/tileset.png",
MAP_TILESET_FILEPATH[] = "assets/house_tileset.png",
BGM_FILEPATH[] = "assets/audio/dooblydoo.mp3",
JUMP_SFX_FILEPATH[] = "assets/audio/bounce.wav";

constexpr int NUMBER_OF_TEXTURES = 1;
constexpr GLint LEVEL_OF_DETAIL = 0;
constexpr GLint TEXTURE_BORDER = 0;

unsigned int LEVEL_1_DATA[] =
{
    128, 131, 131, 131, 131, 131, 133, 80, 80, 132, 131, 131, 131, 131, 131, 131, 131, 131, 131, 117,
    129, 96, 102, 102, 102, 102, 97, 80, 80, 96, 102, 102, 102, 102, 102, 102, 102, 102, 97, 118,
    129, 103, 87, 88, 101, 101, 112, 80, 80, 65, 101, 93, 94, 101, 101, 101, 101, 93, 94, 118,
    129, 157, 158, 159, 155, 156, 100, 80, 80, 98, 99, 109, 110, 99, 160, 161, 99, 109, 110, 118,
    129, 173, 174, 175, 171, 172, 80, 80, 80, 80, 80, 125, 126, 80, 176, 177, 80, 125, 126, 118,
    129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 141, 142, 215, 216, 217, 80, 141, 142, 118,
    129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 82, 80, 231, 232, 233, 80, 80, 82, 118,
    129, 144, 144, 144, 144, 144, 130, 80, 80, 80, 80, 82, 82, 247, 248, 249, 80, 82, 80, 118,
    129, 189, 102, 102, 14, 15, 145, 82, 82, 80, 80, 80, 80, 61, 62, 63, 80, 80, 80, 118,
    129, 205, 80, 82, 30, 31, 145, 80, 80, 82, 80, 80, 80, 77, 80, 79, 80, 80, 80, 118,
    129, 80, 229, 230, 46, 47, 145, 80, 80, 82, 82, 82, 82, 80, 80, 80, 80, 80, 80, 118,
    129, 80, 245, 246, 80, 80, 145, 80, 80, 80, 80, 80, 82, 82, 82, 82, 82, 80, 80, 118,
    129, 80, 80, 80, 80, 80, 134, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 118,
    129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 82, 80, 80, 80, 118,
    115, 116, 116, 116, 116, 116, 130, 80, 80, 119, 116, 116, 116, 116, 116, 116, 116, 116, 116, 114
};

// background
unsigned int BACKGROUND_MAP_DATA[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 103, 0 /*87*/, 88, 0, 80, 112, 0, 0, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 98, 99, 99, 99, 99, 97, 0, 0, 0, 0, 0, 0, 0, 101, 101, 0, 0, 0, 0,
    0, 80, 80, 80, 80, 80, 80, 0, 0, 0, 0, 0, 0, 80, 0, 0, 80, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 80, 80, 0, 80, 80, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 0, 0, 0, 0,
    0, 0, 0, 0, 102, 102, 0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 0, 0, 0, 0,
    0, 0, 0, 80, 80, 80, 0, 0, 0, 0, 0, 0, 0, 80, 0, 80, 0, 0, 0, 0,
    0, 0, 80, 80, 80, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 80, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// ————— VARIABLES ————— //
GameState g_game_state;

SDL_Window* g_display_window;
AppStatus g_app_status = RUNNING;
ShaderProgram g_shader_program;
glm::mat4 g_view_matrix, g_projection_matrix;

float g_previous_ticks = 0.0f,
g_accumulator = 0.0f;


void initialise();
void process_input();
void update();
void render();
void shutdown();

// ————— GENERAL FUNCTIONS ————— //
GLuint load_texture(const char* filepath)
{
    int width, height, number_of_components;
    unsigned char* image = stbi_load(filepath, &width, &height, &number_of_components, STBI_rgb_alpha);

    if (image == NULL)
    {
        LOG("Unable to load image. Make sure the path is correct.");
        assert(false);
    }

    GLuint texture_id;
    glGenTextures(NUMBER_OF_TEXTURES, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, LEVEL_OF_DETAIL, GL_RGBA, width, height, TEXTURE_BORDER, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(image);

    return texture_id;
}

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

    // ————— MAP SET-UP ————— //
    GLuint map_texture_id = load_texture(MAP_TILESET_FILEPATH);

    // Create the background map first
    g_game_state.background_map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);

    // Then create the main map with all the visible elements
    g_game_state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, LEVEL_1_DATA, map_texture_id, 1.0f, 16, 16);

    // ————— PLAYER SET-UP ————— //
    GLuint player_texture_id = load_texture(SPRITESHEET_FILEPATH);

    // Define the walking animation frames for each direction
    int player_walking_animation[6][6] =
    {
        { 2, 8, 14 },  // LEFT
        { 4, 10, 16 },  // RIGHT
        { 5, 11, 17 },   // UP
        { 3, 9, 15 }    // DOWN
    };

    // Define acceleration vector (was missing before)
    glm::vec3 player_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);

    g_game_state.player = new Entity(
        player_texture_id,         // texture id
        5.0f,                      // speed
        player_acceleration,       // acceleration (fixed)
        3.0f,                      // jumping power
        player_walking_animation,  // animation index sets
        0.0f,                      // animation time
        3,                         // animation frame amount
        0,                         // current animation index
        6,                         // animation column amount
        6,                         // animation row amount
        0.9f,                      // width
        0.9f,                      // height
        PLAYER
    );

    GLuint key_texture_id = load_texture("assets/key.png");  

    // Create key entity (initially inactive)
    g_game_state.key = new Entity(
        key_texture_id,         // texture id
        0.0f,                   // speed 
        0.5f,                   // width 
        0.5f,                   // height 
        PLATFORM                // entity type
    );

    // Initially deactivate the key
    g_game_state.key->deactivate();
    g_game_state.key_spawned = false;
    g_game_state.key_collected = false;

    // Set player starting position to be in the middle of the wooden floor area
    g_game_state.player->set_position(glm::vec3(10.0f, -8.0f, 0.0f));

    // Jumping
    g_game_state.player->set_jumping_power(5.0f);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    g_game_state.bgm = Mix_LoadMUS(BGM_FILEPATH);
    //    Mix_PlayMusic(g_game_state.bgm, -1);
    //    Mix_VolumeMusic(MIX_MAX_VOLUME / 16.0f);

    g_game_state.jump_sfx = Mix_LoadWAV(JUMP_SFX_FILEPATH);

    // ————— BLENDING ————— //
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void process_input()
{
    // If the game is frozen, ignore player input but still check for quit events
    if (g_game_state.game_frozen) {
        // Set player movement to zero to ensure they stop
        g_game_state.player->set_movement(glm::vec3(0.0f));

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
            case SDL_WINDOWEVENT_CLOSE:
                g_app_status = TERMINATED;
                break;
            default:
                break;
            }
        }
        return; // Skip the rest of input processing
    }

    // Normal input processing when not frozen
    g_game_state.player->set_movement(glm::vec3(0.0f));

    // Set default speed (walking speed)
    float walking_speed = 5.0f;
    float sprint_speed = 8.0f;

    // Default to walking speed
    g_game_state.player->set_speed(walking_speed);

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
            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    // Check if left shift is pressed for sprint
    if (key_state[SDL_SCANCODE_LSHIFT]) {
        g_game_state.player->set_speed(sprint_speed);
    }

    // Handle horizontal movement
    if (key_state[SDL_SCANCODE_A])      g_game_state.player->move_left();
    else if (key_state[SDL_SCANCODE_D]) g_game_state.player->move_right();

    // Handle vertical movement independently (not using else if)
    if (key_state[SDL_SCANCODE_W])      g_game_state.player->move_up();
    else if (key_state[SDL_SCANCODE_S]) g_game_state.player->move_down();

    if (glm::length(g_game_state.player->get_movement()) > 1.0f)
        g_game_state.player->normalise_movement();
}

void update()
{
    float ticks = (float)SDL_GetTicks() / MILLISECONDS_IN_SECOND;
    float delta_time = ticks - g_previous_ticks;
    g_previous_ticks = ticks;

    // Handle the freeze timer if the game is frozen
    if (g_game_state.game_frozen) {
        g_game_state.freeze_timer -= delta_time;

        // If the freeze timer is up, unfreeze the game
        if (g_game_state.freeze_timer <= 0.0f) {
            g_game_state.game_frozen = false;
        }

        // Still update the camera even when frozen
        g_view_matrix = glm::mat4(1.0f);
        g_view_matrix = glm::translate(g_view_matrix, glm::vec3(
            -g_game_state.player->get_position().x,
            -g_game_state.player->get_position().y,
            0.0f));

        return; // Skip the rest of the update when frozen
    }

    delta_time += g_accumulator;

    if (delta_time < FIXED_TIMESTEP)
    {
        g_accumulator = delta_time;
        return;
    }

    while (delta_time >= FIXED_TIMESTEP)
    {
        g_game_state.player->update(FIXED_TIMESTEP, g_game_state.player, NULL, 0,
            g_game_state.map);

        // If the key is active, update it too
        if (g_game_state.key_spawned && !g_game_state.key_collected) {
            g_game_state.key->update(FIXED_TIMESTEP, g_game_state.player, NULL, 0, g_game_state.map);
        }

        delta_time -= FIXED_TIMESTEP;
    }

    g_accumulator = delta_time;

    // Check if player is on the trigger tile (row 6, column 2)
    glm::vec3 player_pos = g_game_state.player->get_position();
    int tile_x = floor((player_pos.x + 0.5f));
    int tile_y = floor(-(player_pos.y - 0.5f));

    // Check if player is on the trigger tile
    if (!g_game_state.key_spawned && !g_game_state.key_collected &&
        tile_x >= 1 && tile_x <= 3 && tile_y == 6) {

        // Set the key to spawn at the fixed location (row 6, column 2)
        float key_x = 2.0f; // Column 2 (0-indexed)
        float key_y = -6.0f; // Row 6 (0-indexed, negative because y goes down)

        g_game_state.key_position = glm::vec3(key_x, key_y, 0.0f);
        g_game_state.key->set_position(g_game_state.key_position);
        g_game_state.key->activate();
        g_game_state.key_spawned = true;

        // Freeze the game for 1 second when the key spawns
        g_game_state.game_frozen = true;
        g_game_state.freeze_timer = g_game_state.FREEZE_DURATION;

        // Force player to stop moving immediately
        g_game_state.player->set_movement(glm::vec3(0.0f));
        g_game_state.player->set_velocity(glm::vec3(0.0f));
    }

    // Check if player collects the key using check_collision
    if (g_game_state.key_spawned && !g_game_state.key_collected) {
        if (g_game_state.player->check_collision(g_game_state.key)) {
            g_game_state.key_collected = true;
            g_game_state.key->deactivate();
        }
    }

    // Camera follows the player in both X and Y directions
    g_view_matrix = glm::mat4(1.0f);
    g_view_matrix = glm::translate(g_view_matrix, glm::vec3(
        -g_game_state.player->get_position().x,
        -g_game_state.player->get_position().y,
        0.0f));
}

void render()
{
    g_shader_program.set_view_matrix(g_view_matrix);

    glClear(GL_COLOR_BUFFER_BIT);

    // Render in layers: background first, then main map, then entities
    g_game_state.background_map->render(&g_shader_program);
    g_game_state.map->render(&g_shader_program);

    // Render the key if it's spawned and not collected
    if (g_game_state.key_spawned && !g_game_state.key_collected) {
        g_game_state.key->render(&g_shader_program);
    }

    // Render the player
    g_game_state.player->render(&g_shader_program);

    // If key is collected, render it in the UI (top-right corner)
    if (g_game_state.key_collected) {
        // Save the current view matrix
        glm::mat4 original_view_matrix = g_view_matrix;

        // Set up UI view (fixed position regardless of camera)
        glm::mat4 ui_view_matrix = glm::mat4(1.0f);
        g_shader_program.set_view_matrix(ui_view_matrix);

        // Position the key in the top-right corner of the screen
        glm::mat4 key_model_matrix = glm::mat4(1.0f);
        key_model_matrix = glm::translate(key_model_matrix, glm::vec3(7.0f, 5.0f, 0.0f));
        key_model_matrix = glm::scale(key_model_matrix, glm::vec3(0.5f, 0.5f, 1.0f));
        g_shader_program.set_model_matrix(key_model_matrix);

        // Render the key in the UI
        float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
        float tex_coords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };

        glBindTexture(GL_TEXTURE_2D, g_game_state.key->get_texture_id());

        glVertexAttribPointer(g_shader_program.get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
        glEnableVertexAttribArray(g_shader_program.get_position_attribute());
        glVertexAttribPointer(g_shader_program.get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
        glEnableVertexAttribArray(g_shader_program.get_tex_coordinate_attribute());

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(g_shader_program.get_position_attribute());
        glDisableVertexAttribArray(g_shader_program.get_tex_coordinate_attribute());

        // Restore the original view matrix for the next frame
        g_shader_program.set_view_matrix(original_view_matrix);
    }

    SDL_GL_SwapWindow(g_display_window);
}

void shutdown()
{
    SDL_Quit();

    delete[] g_game_state.enemies;
    delete g_game_state.player;
    delete g_game_state.key; 
    delete g_game_state.map;
    delete g_game_state.background_map;
    Mix_FreeChunk(g_game_state.jump_sfx);
    Mix_FreeMusic(g_game_state.bgm);
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
