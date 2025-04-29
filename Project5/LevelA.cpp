#include "LevelA.h"
#include "Utility.h"

LevelA::LevelA() {
    // Initialize level data arrays
    unsigned int level_data[] = {
        128, 131, 131, 131, 131, 131, 133, 80, 80, 132, 131, 131, 131, 131, 131, 131, 131, 131, 131, 117,
        129, 96, 102, 102, 102, 102, 97, 80, 80, 96, 102, 102, 102, 102, 102, 102, 102, 102, 97, 118,
        129, 103, 87, 88, 101, 101, 112, 80, 80, 65, 101, 93, 94, 101, 101, 101, 101, 93, 94, 118,
        129, 157, 158, 159, 155, 156, 100, 80, 80, 98, 99, 109, 110, 99, 160, 161, 99, 109, 110, 118,
        129, 173, 174, 175, 171, 172, 80, 80, 80, 80, 80, 125, 126, 80, 176, 177, 80, 125, 126, 118,
        129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 141, 142, 215, 216, 217, 80, 141, 142, 118,
        129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 82, 80, 231, 232, 233, 80, 80, 82, 118,
        129, 144, 144, 144, 144, 144, 130, 82, 80, 80, 80, 82, 82, 247, 248, 249, 80, 82, 80, 118,
        129, 189, 102, 102, 14, 15, 145, 82, 82, 80, 80, 80, 80, 61, 62, 63, 80, 80, 80, 118,
        129, 205, 80, 82, 30, 31, 145, 80, 80, 82, 80, 80, 80, 77, 80, 79, 80, 80, 80, 118,
        129, 80, 229, 230, 46, 47, 145, 80, 80, 82, 82, 82, 82, 80, 80, 80, 80, 80, 80, 118,
        129, 80, 245, 246, 80, 80, 145, 80, 80, 80, 80, 80, 82, 82, 82, 82, 82, 80, 80, 118,
        129, 80, 80, 80, 80, 80, 134, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 118,
        129, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 82, 80, 80, 80, 118,
        115, 116, 116, 116, 116, 116, 130, 80, 80, 119, 116, 116, 116, 116, 116, 116, 116, 116, 116, 114
    };

    unsigned int background_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 103, 0, 88, 80, 80, 112, 80, 80, 103, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 98, 99, 99, 99, 99, 97, 80, 80, 80, 80, 80, 80, 80, 101, 101, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 0, 0, 0, 102, 102, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    // Copy the data to member arrays
    for (int i = 0; i < LEVEL1_WIDTH * LEVEL1_HEIGHT; i++) {
        LEVEL_1_DATA[i] = level_data[i];
        BACKGROUND_MAP_DATA[i] = background_data[i];
    }

    // Initialize pointers to nullptr
    m_game_state.player = nullptr;
    m_game_state.enemies = nullptr;
    m_game_state.map = nullptr;
    m_background_map = nullptr;
    m_key = nullptr;
    m_game_state.bgm = nullptr;
    m_game_state.jump_sfx = nullptr;
    m_game_state.next_scene_id = -1; // Initialize to -1, meaning no scene change
}

LevelA::~LevelA() {
    // Cleanup is handled in the main shutdown function
    // But we should clean up our background map
    if (m_background_map != nullptr) {
        delete m_background_map;
    }
}

void LevelA::initialise() {
    // MAP SET-UP
    GLuint map_texture_id = Utility::load_texture(MAP_TILESET_FILEPATH);

    // Create the background map first
    m_background_map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);

    // Then create the main map with all the visible elements
    m_game_state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, LEVEL_1_DATA, map_texture_id, 1.0f, 16, 16);

    // PLAYER SET-UP
    GLuint player_texture_id = Utility::load_texture(SPRITESHEET_FILEPATH);

    // Define the walking animation frames for each direction
    int player_walking_animation[6][6] =
    {
        { 2, 8, 14 },  // LEFT
        { 4, 10, 16 },  // RIGHT
        { 5, 11, 17 },   // UP
        { 3, 9, 15 }    // DOWN
    };

    // Define acceleration vector
    glm::vec3 player_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);

    m_game_state.player = new Entity(
        player_texture_id,         // texture id
        5.0f,                      // speed
        player_acceleration,       // acceleration
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

    GLuint key_texture_id = Utility::load_texture(KEY_FILEPATH);

    // Create key entity (initially inactive)
    m_key = new Entity(
        key_texture_id,         // texture id
        0.0f,                   // speed 
        0.5f,                   // width 
        0.5f,                   // height 
        PLATFORM                // entity type
    );

    // Initially deactivate the key
    m_key->deactivate();
    m_key_spawned = false;
    m_key_collected = false;

    // Set player starting position to be in the middle of the wooden floor area
    m_game_state.player->set_position(glm::vec3(7.0f, -14.0f, 0.0f));

    // Jumping
    m_game_state.player->set_jumping_power(5.0f);

    // Audio setup
    m_game_state.bgm = Mix_LoadMUS(BGM_FILEPATH);
    m_game_state.jump_sfx = Mix_LoadWAV(JUMP_SFX_FILEPATH);

    // Uncomment if you want music to play
    // Mix_PlayMusic(m_game_state.bgm, -1);
    // Mix_VolumeMusic(MIX_MAX_VOLUME / 16.0f);
}

void LevelA::process_input() {
    // If the game is frozen, ignore player input but still check for quit events
    if (m_game_frozen) {
        // Set player movement to zero to ensure they stop
        m_game_state.player->set_movement(glm::vec3(0.0f));
        return; // Skip the rest of input processing
    }

    // Normal input processing when not frozen
    m_game_state.player->set_movement(glm::vec3(0.0f));

    // Set default speed (walking speed)
    float walking_speed = 5.0f;
    float sprint_speed = 8.0f;

    // Default to walking speed
    m_game_state.player->set_speed(walking_speed);

    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    // Check if left shift is pressed for sprint
    if (key_state[SDL_SCANCODE_LSHIFT]) {
        m_game_state.player->set_speed(sprint_speed);
    }

    // Handle horizontal movement
    if (key_state[SDL_SCANCODE_A])      m_game_state.player->move_left();
    else if (key_state[SDL_SCANCODE_D]) m_game_state.player->move_right();

    // Handle vertical movement independently (not using else if)
    if (key_state[SDL_SCANCODE_W])      m_game_state.player->move_up();
    else if (key_state[SDL_SCANCODE_S]) m_game_state.player->move_down();

    if (glm::length(m_game_state.player->get_movement()) > 1.0f)
        m_game_state.player->normalise_movement();
}

void LevelA::update(float delta_time) {
    // Handle the freeze timer if the game is frozen
    if (m_game_frozen) {
        m_freeze_timer -= delta_time;

        // If the freeze timer is up, unfreeze the game
        if (m_freeze_timer <= 0.0f) {
            m_game_frozen = false;
        }
        return; // Skip the rest of the update when frozen
    }

    // Process player input
    process_input();

    // Update player
    m_game_state.player->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);

    // If the key is active, update it too
    if (m_key_spawned && !m_key_collected) {
        m_key->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
    }

    // Check if player is on the trigger tile (row 6, column 2)
    glm::vec3 player_pos = m_game_state.player->get_position();
    int tile_x = floor((player_pos.x + 0.5f));
    int tile_y = floor(-(player_pos.y - 0.5f));

    // Check if player is on the trigger tile
    if (!m_key_spawned && !m_key_collected &&
        tile_x >= 1 && tile_x <= 3 && tile_y == 6) {

        // Set the key to spawn at the fixed location (row 6, column 2)
        float key_x = 2.0f; // Column 2 (0-indexed)
        float key_y = -6.0f; // Row 6 (0-indexed, negative because y goes down)

        m_key_position = glm::vec3(key_x, key_y, 0.0f);
        m_key->set_position(m_key_position);
        m_key->activate();
        m_key_spawned = true;

        // Freeze the game for a short duration when the key spawns
        m_game_frozen = true;
        m_freeze_timer = FREEZE_DURATION;

        // Force player to stop moving immediately
        m_game_state.player->set_movement(glm::vec3(0.0f));
        m_game_state.player->set_velocity(glm::vec3(0.0f));
    }

    // Check if player collects the key using check_collision
    if (m_key_spawned && !m_key_collected) {
        if (m_game_state.player->check_collision(m_key)) {
            m_key_collected = true;
            m_key->deactivate();
        }
    }
}

void LevelA::render(ShaderProgram* program) {
    // Render in layers: background first, then main map, then entities
    if (m_background_map != nullptr) {
        m_background_map->render(program);
    }

    m_game_state.map->render(program);

    // Render the key if it's spawned and not collected
    if (m_key_spawned && !m_key_collected) {
        m_key->render(program);
    }

    // Render the player
    m_game_state.player->render(program);

    // If key is collected, render it in the UI (top-right corner)
    if (m_key_collected) {
        // Save the current view matrix - we'll create a new one for UI
        glm::mat4 original_view_matrix = glm::mat4(1.0f); // Identity matrix

        // Set up UI view (fixed position regardless of camera)
        glm::mat4 ui_view_matrix = glm::mat4(1.0f);
        program->set_view_matrix(ui_view_matrix);

        // Position the key in the top-right corner of the screen
        glm::mat4 key_model_matrix = glm::mat4(1.0f);
        key_model_matrix = glm::translate(key_model_matrix, glm::vec3(7.0f, 5.0f, 0.0f));
        key_model_matrix = glm::scale(key_model_matrix, glm::vec3(0.5f, 0.5f, 1.0f));
        program->set_model_matrix(key_model_matrix);

        // Render the key in the UI
        float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
        float tex_coords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };

        glBindTexture(GL_TEXTURE_2D, m_key->get_texture_id());

        glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
        glEnableVertexAttribArray(program->get_position_attribute());
        glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
        glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(program->get_position_attribute());
        glDisableVertexAttribArray(program->get_tex_coordinate_attribute());

        // Restore the original view matrix for the next frame
        program->set_view_matrix(original_view_matrix);
    }

    if (m_key_collected == true && m_game_state.player->get_position().y >= -1.0f) {
        m_game_state.next_scene_id = 1; 
    }
}