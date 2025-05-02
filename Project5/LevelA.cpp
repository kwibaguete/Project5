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

    // Copy data to member arrays
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
    m_game_state.next_scene_id = -1; 

    // Initialize enemy related variables
    m_enemy_active = true;
    m_enemy_following = false;
    m_enemy_timer = 5.0f; 
    m_enemy_entry_position = glm::vec3(18.0f, -2.0f, 0.0f); // Entry position for enemy
}

LevelA::~LevelA() {
    // Clean up our background map
    if (m_background_map != nullptr) {
        delete m_background_map;
    }
}

void LevelA::initialise() {
    // MAP SET-UP
    GLuint map_texture_id = Utility::load_texture(MAP_TILESET_FILEPATH);

    // Create the background map first
    m_background_map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);

    // Then create the main map 
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

    m_key = new Entity(
        key_texture_id,         // texture id
        0.0f,                   // speed 
        0.5f,                   // width 
        0.5f,                   // height 
        PLATFORM                // entity type
    );

    // Key is initially deactivated
    m_key->deactivate();
    m_key_spawned = false;
    m_key_collected = false;

    m_game_state.player->set_position(glm::vec3(7.0f, -13.0f, 0.0f));

    // Jumping
    m_game_state.player->set_jumping_power(5.0f);

    // Audio setup
    m_game_state.bgm = Mix_LoadMUS(BGM_FILEPATH);
    m_game_state.jump_sfx = Mix_LoadWAV(JUMP_SFX_FILEPATH);

    // MUSIC!!!!!!!
    // Mix_PlayMusic(m_game_state.bgm, -1);
    // Mix_VolumeMusic(MIX_MAX_VOLUME / 16.0f);
}

void LevelA::process_input() {
    // If the game is frozen, ignore player input
    if (m_game_frozen) {
        // Force player to stop
        m_game_state.player->set_movement(glm::vec3(0.0f));
        return; 
    }

    m_game_state.player->set_movement(glm::vec3(0.0f));

    float walking_speed = 5.0f;
    float sprint_speed = 8.0f;

    // Default to walking speed
    m_game_state.player->set_speed(walking_speed);

    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    // Check if left shift is pressed for sprint
    if (key_state[SDL_SCANCODE_LSHIFT]) {
        m_game_state.player->set_speed(sprint_speed);
    }

    // Right left movement
    if (key_state[SDL_SCANCODE_A])      m_game_state.player->move_left();
    else if (key_state[SDL_SCANCODE_D]) m_game_state.player->move_right();

    // Up down movement
    if (key_state[SDL_SCANCODE_W])      m_game_state.player->move_up();
    else if (key_state[SDL_SCANCODE_S]) m_game_state.player->move_down();

    if (glm::length(m_game_state.player->get_movement()) > 1.0f)
        m_game_state.player->normalise_movement();
}

void LevelA::update(float delta_time) {
    if (m_game_frozen) {
        m_freeze_timer -= delta_time;

        // If the freeze timer is up, unfreeze the game
        if (m_freeze_timer <= 0.0f) {
            m_game_frozen = false;
            m_show_escape_message = false; // Reset the message flag 
        }
        return; 
    }

    // Process player input
    process_input();

    // Update player
    m_game_state.player->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);

    // Update enemy timer if active
    if (m_enemy_active) {
        if (m_enemy_timer > 0) {
            m_enemy_timer -= delta_time;
            if (m_enemy_timer <= 0) {
                // Timer expired, start following
                m_enemy_following = true;

                // Create enemy if it doesn't exist
                if (m_game_state.enemies == nullptr) {
                    // Create an array of enemy pointers
                    m_game_state.enemies = new Entity * [ENEMY_COUNT];

                    // Initialize the enemy
                    GLuint enemy_texture_id = Utility::load_texture(ENEMY_FILEPATH);

                    int enemy_walking_animation[6][6] =
                    {
                        { 2, 8, 14 },  // LEFT
                        { 4, 10, 16 },  // RIGHT
                        { 5, 11, 17 },   // UP
                        { 3, 9, 15 }    // DOWN
                    };

                    glm::vec3 enemy_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);

                    m_game_state.enemies[0] = new Entity(
                        enemy_texture_id,         // texture id
                        6.0f,                     // speed
                        enemy_acceleration,       // acceleration
                        3.0f,                     // jumping power
                        enemy_walking_animation,  // animation index sets
                        0.0f,                     // animation time
                        3,                        // animation frame amount
                        0,                        // current animation index
                        6,                        // animation column amount
                        6,                        // animation row amount
                        0.9f,                     // width
                        0.9f,                     // height
                        ENEMY
                    );
                }

                // Place the enemy at entry position
                m_game_state.enemies[0]->set_position(m_enemy_entry_position);
                m_game_state.enemies[0]->activate();
            }
        }

        // Update enemy if it's following
        if (m_enemy_following && m_game_state.enemies != nullptr) {
            update_enemy(delta_time);

            if (m_game_state.enemies[0]->check_collision(m_game_state.player)) {
                m_game_state.next_scene_id = 2; 
            }
        }
    }

    // If the key is active, update it too
    if (m_key_spawned && !m_key_collected) {
        m_key->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
    }

    // Check if player is on the trigger tile 
    glm::vec3 player_pos = m_game_state.player->get_position();
    int tile_x = floor((player_pos.x + 0.5f));
    int tile_y = floor(-(player_pos.y - 0.5f));

    // Check if player is on the trigger tile
    if (!m_key_spawned && !m_key_collected &&
        tile_x >= 1 && tile_x <= 3 && tile_y == 6) {

        float key_x = 2.0f;
        float key_y = -6.0f;

        m_key_position = glm::vec3(key_x, key_y, 0.0f);
        m_key->set_position(m_key_position);
        m_key->activate();
        m_key_spawned = true;

        // Freeze game
        m_game_frozen = true;
        m_freeze_timer = FREEZE_DURATION;
        m_show_escape_message = false;

        // Player no move
        m_game_state.player->set_movement(glm::vec3(0.0f));
        m_game_state.player->set_velocity(glm::vec3(0.0f));
    }

    // Check if player is trying to leave without the key
    if (!m_key_collected && m_game_state.player->get_position().y <= -14.0f) {
        // Only trigger this once when the condition is first met
        if (!m_game_frozen) {
            m_game_frozen = true;
            m_freeze_timer = 2.0f; 
            m_show_escape_message = true; 

            // No move
            m_game_state.player->set_movement(glm::vec3(0.0f));
            m_game_state.player->set_velocity(glm::vec3(0.0f));
        }
    }

    if (m_key_spawned && !m_key_collected) {
        if (m_game_state.player->check_collision(m_key)) {
            m_key_collected = true;
            m_key->deactivate();
        }
    }
}


void LevelA::update_enemy(float delta_time) {
    // If enemy is not active or game is frozen, don't update
    if (!m_enemy_active || !m_enemy_following || m_game_frozen) {
        return;
    }


    glm::vec3 enemy_pos = m_game_state.enemies[0]->get_position();
    glm::vec3 player_pos = m_game_state.player->get_position();

    // Calculate direction to player
    glm::vec3 direction = glm::normalize(player_pos - enemy_pos);

    // Check for obstacles in the current direction
    bool obstacle_ahead = false;

    // Determine which direction the enemy is currently facing
    glm::vec3 facing_direction(0.0f);
    if (m_game_state.enemies[0]->get_movement().x > 0) {
        facing_direction = glm::vec3(1.0f, 0.0f, 0.0f); // Right
    }
    else if (m_game_state.enemies[0]->get_movement().x < 0) {
        facing_direction = glm::vec3(-1.0f, 0.0f, 0.0f); // Left
    }
    else if (m_game_state.enemies[0]->get_movement().y > 0) {
        facing_direction = glm::vec3(0.0f, 1.0f, 0.0f); // Up
    }
    else if (m_game_state.enemies[0]->get_movement().y < 0) {
        facing_direction = glm::vec3(0.0f, -1.0f, 0.0f); // Down
    }

    // Check if there's an obstacle in the facing direction
    if (glm::length(facing_direction) > 0) {
        obstacle_ahead = check_collision_in_direction(m_game_state.enemies[0], facing_direction);
    }

    // Reset enemy movement
    m_game_state.enemies[0]->set_movement(glm::vec3(0.0f));

    // If there's an obstacle ahead, change direction toward player
    if (obstacle_ahead) {
        // Determine if horizontal or vertical movement is better
        float x_diff = std::abs(player_pos.x - enemy_pos.x);
        float y_diff = std::abs(player_pos.y - enemy_pos.y);

        if (x_diff > y_diff) {
            // Try horizontal movement
            if (player_pos.x > enemy_pos.x) {
                m_game_state.enemies[0]->move_right();
            }
            else {
                m_game_state.enemies[0]->move_left();
            }
        }
        else {
            // Try vertical movement
            if (player_pos.y > enemy_pos.y) {
                m_game_state.enemies[0]->move_up();
            }
            else {
                m_game_state.enemies[0]->move_down();
            }
        }
    }
    else {
        // No obstacle, move directly toward player
        if (std::abs(direction.x) > std::abs(direction.y)) {
            // Move horizontally
            if (direction.x > 0) {
                m_game_state.enemies[0]->move_right();
            }
            else {
                m_game_state.enemies[0]->move_left();
            }
        }
        else {
            // Move vertically
            if (direction.y > 0) {
                m_game_state.enemies[0]->move_up();
            }
            else {
                m_game_state.enemies[0]->move_down();
            }
        }
    }

    m_game_state.enemies[0]->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
}

bool LevelA::check_collision_in_direction(Entity* entity, glm::vec3 direction) {
    // Check if there's a collision in the given direction
    glm::vec3 test_position = entity->get_position() + direction * 0.5f;

    // Create a probe point in the direction we're checking
    float penetration_x = 0;
    float penetration_y = 0;

    return m_game_state.map->is_solid(test_position, &penetration_x, &penetration_y);
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

    // Render the enemy if active and following
    if (m_enemy_active && m_enemy_following && m_game_state.enemies != nullptr) {
        m_game_state.enemies[0]->render(program);
    }

    // Only display the text if the game is frozen AND we should show the escape message
    if (m_game_frozen && m_show_escape_message) {
        // Save the current view matrix for later
        glm::mat4 original_view_matrix = glm::mat4(1.0f);

        // Set up UI view 
        glm::mat4 ui_view_matrix = glm::mat4(1.0f);
        program->set_view_matrix(ui_view_matrix);

        // Load the font texture (only once)
        static GLuint font_texture_id = Utility::load_texture("assets/font1.png");

        Utility::draw_text(program,
            font_texture_id,
            "Find a way to escape here",
            0.5f,   // text size
            0.01f,  // spacing
            glm::vec3(-6.0f, -2.5f, 0.0f)); 

        // Restore the original view matrix
        program->set_view_matrix(original_view_matrix);
    }

    // If key is collected, render it in the UI (top-right corner)
    if (m_key_collected) {
        // Save the current view matrix 
        glm::mat4 original_view_matrix = glm::mat4(1.0f); 

        // Set up UI view 
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

    // Check if player has the final key from Level C and is at the exit
    extern bool g_has_final_key;
    if (g_has_final_key &&
        m_game_state.player->get_position().y <= -13.5f &&
        m_game_state.player->get_position().y >= -14.5f &&
        m_game_state.player->get_position().x >= 6.5f &&
        m_game_state.player->get_position().x <= 7.5f) {

        m_game_state.next_scene_id = 4; // Assuming 4 is the WinScene ID
    }

    if (m_key_collected == true && m_game_state.player->get_position().y >= -1.0f) {
        m_game_state.next_scene_id = 1;
    }
}
