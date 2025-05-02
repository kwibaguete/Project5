/**
* Author: Belinda Weng
* Assignment: your house
* Date due: 5/2/2025, 2:00pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "LevelC.h"
#include "Utility.h"

LevelC::LevelC() {
    unsigned int level_data[] = {
        0, 0, 0, 0, 0, 0, 128, 131, 131, 131, 131, 131, 131, 117, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 96, 102, 102, 102, 102, 97, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 103, 101, 87, 88, 101, 112, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 98, 99, 99, 99, 99, 100, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 80, 80, 80, 80, 80, 80, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 80, 80, 80, 80, 80, 80, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 80, 80, 80, 80, 80, 80, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 80, 80, 80, 80, 80, 80, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 129, 80, 80, 80, 80, 80, 80, 118, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 115, 116, 130, 80, 80, 119, 116, 114, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 129, 80, 80, 118, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 129, 80, 80, 118, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 129, 80, 80, 118, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 129, 80, 80, 118, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 129, 80, 80, 118, 0, 0, 0, 0, 0, 0, 0, 0
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
    for (int i = 0; i < LEVEL3_WIDTH * LEVEL3_HEIGHT; i++) {
        LEVEL_3_DATA[i] = level_data[i];
        BACKGROUND_MAP_DATA[i] = background_data[i];
    }


    m_game_state.player = nullptr;
    m_game_state.enemies = nullptr;
    m_game_state.map = nullptr;
    m_game_state.bgm = nullptr;
    m_game_state.jump_sfx = nullptr;
    m_game_state.next_scene_id = -1; 


    m_number_of_enemies = 1; 

    // Initialize enemy state
    m_enemy_active = false;
    m_enemy_following = false;
}

LevelC::~LevelC() {
    // Clean up the enemies array
    if (m_game_state.enemies) {
        delete m_game_state.enemies[0];
        delete[] m_game_state.enemies;
    }
}

void LevelC::initialise() {

    GLuint map_texture_id = Utility::load_texture(MAP_TILESET_FILEPATH);


    Map* background_map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);


    m_game_state.map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, LEVEL_3_DATA, map_texture_id, 1.0f, 16, 16);

    // PLAYER SET-UP
    GLuint player_texture_id = Utility::load_texture(SPRITESHEET_FILEPATH);

    // ENEMY SET-UP
    GLuint enemy_texture_id = Utility::load_texture(ENEMY_FILEPATH);

    // Define the walking animation frames for each direction
    int player_walking_animation[6][6] =
    {
        { 2, 8, 14 },  // LEFT
        { 4, 10, 16 },  // RIGHT
        { 5, 11, 17 },   // UP
        { 3, 9, 15 }    // DOWN
    };

    int enemy_walking_animation[6][6] =
    {
        { 2, 8, 14 },  // LEFT
        { 4, 10, 16 },  // RIGHT
        { 5, 11, 17 },   // UP
        { 3, 9, 15 }    // DOWN
    };

    // Define acceleration vector
    glm::vec3 player_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 enemy_acceleration = glm::vec3(0.0f, 0.0f, 0.0f);

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


    m_game_state.enemies = new Entity * [1];

    // Initialize the enemy
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


    m_game_state.enemies[0]->set_position(glm::vec3(9.5f, -4.0f, 0.0f));
    m_game_state.enemies[0]->face_up();


    m_game_state.enemies[0]->deactivate();
    m_enemy_active = false;
    m_enemy_following = false;

    GLuint key_texture_id = Utility::load_texture(KEY_FILEPATH);

    m_key = new Entity(
        key_texture_id,         // texture id
        0.0f,                   // speed 
        0.5f,                   // width 
        0.5f,                   // height 
        PLATFORM                // entity type
    );

    m_key_spawned = true;
    m_key_collected = false;
    m_key->activate();

    m_key_position = glm::vec3(9.5f, -6.0f, 0.0f);
    m_key->set_position(m_key_position);


    m_game_state.player->set_position(glm::vec3(9.0f, -13.0f, 0.0f));

    // Jumping
    m_game_state.player->set_jumping_power(5.0f);

    // Audio setup
    m_game_state.bgm = Mix_LoadMUS(BGM_FILEPATH);
    m_game_state.jump_sfx = Mix_LoadWAV(JUMP_SFX_FILEPATH);

    // Uncomment for music!!!!!!!!!!!!!!!!!!!!!
    // Mix_PlayMusic(m_game_state.bgm, -1);
    // Mix_VolumeMusic(MIX_MAX_VOLUME / 16.0f);
}

void LevelC::process_input() {
    if (m_game_frozen) {
        m_game_state.player->set_movement(glm::vec3(0.0f));
        return; 
    }

    m_game_state.player->set_movement(glm::vec3(0.0f));

    float walking_speed = 5.0f;
    float sprint_speed = 8.0f;

    // Default to walking speed
    m_game_state.player->set_speed(walking_speed);

    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    if (key_state[SDL_SCANCODE_LSHIFT]) {
        m_game_state.player->set_speed(sprint_speed);
    }

    if (key_state[SDL_SCANCODE_A])      m_game_state.player->move_left();
    else if (key_state[SDL_SCANCODE_D]) m_game_state.player->move_right();

    if (key_state[SDL_SCANCODE_W])      m_game_state.player->move_up();
    else if (key_state[SDL_SCANCODE_S]) m_game_state.player->move_down();

    if (glm::length(m_game_state.player->get_movement()) > 1.0f)
        m_game_state.player->normalise_movement();
}

bool LevelC::check_collision_in_direction(Entity* entity, glm::vec3 direction) {
    // Check if there's a collision in the given direction
    glm::vec3 test_position = entity->get_position() + direction * 0.5f;

    // Create a probe point in the direction we're checking
    float penetration_x = 0;
    float penetration_y = 0;

    return m_game_state.map->is_solid(test_position, &penetration_x, &penetration_y);
}

void LevelC::update_enemy(float delta_time) {
    // If enemy is not active, don't update
    if (!m_enemy_active) {
        return;
    }

    if (m_game_frozen) {
        m_game_state.enemies[0]->set_movement(glm::vec3(0.0f));
        return;
    }

    // If enemy is not following yet, don't move
    if (!m_enemy_following) {
        m_game_state.enemies[0]->set_movement(glm::vec3(0.0f));
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
}

void LevelC::update(float delta_time) {
    if (m_game_frozen) {
        m_freeze_timer -= delta_time;

        // If the freeze timer is up, unfreeze
        if (m_freeze_timer <= 0.0f) {
            m_game_frozen = false;

            // Start the enemy following when the game unfreezes
            if (m_enemy_active && !m_enemy_following) {
                m_enemy_following = true;
            }
        }
    }

    // Update key position if it's spawned and not collected
    if (m_key_spawned && !m_key_collected) {
        m_key->set_position(m_key_position);

        m_key->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
    }

    // Process player input
    process_input();

    // Update player
    m_game_state.player->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);

    // Update enemy timer if active but not following
    if (m_enemy_active && !m_enemy_following) {
        if (m_enemy_timer > 0) {
            m_enemy_timer -= delta_time;
            if (m_enemy_timer <= 0) {
                // Timer expired, start following
                m_enemy_following = true;

                // If enemy was transferred from another level, place it at entry position
                if (m_game_state.enemies[0]->get_position().y < -20.0f) {
                    m_game_state.enemies[0]->set_position(glm::vec3(9.0f, -12.0f, 0.0f));
                }
            }
        }
    }

    // Update enemy
    update_enemy(delta_time);

    // If enemy is active, update it
    if (m_enemy_active) {
        m_game_state.enemies[0]->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);

        // Check for collision with player
        if (m_enemy_following && m_game_state.enemies[0]->check_collision(m_game_state.player)) {
            m_game_state.next_scene_id = 2;
        }
    }

    if (m_key_spawned && !m_key_collected) {
        if (m_game_state.player->check_collision(m_key)) {
            m_key_collected = true;
            m_key->deactivate();

            // Freeze game
            m_game_frozen = true;
            m_freeze_timer = FREEZE_DURATION;

            // Force player to stop moving
            m_game_state.player->set_movement(glm::vec3(0.0f));
            m_game_state.player->set_velocity(glm::vec3(0.0f));

            // Activate enemy
            m_game_state.enemies[0]->activate();
            m_game_state.enemies[0]->face_down();
            m_enemy_active = true;
            m_enemy_following = false; 
        }
    }

    // Check if player is at the bottom of the level to go back to Level B
    if (m_game_state.player->get_position().y <= -14.0f) {
        m_game_state.next_scene_id = 1;  
    }
}

void LevelC::render(ShaderProgram* program) {
    m_game_state.map->render(program);

    m_game_state.player->render(program);

    // Render the enemy if active
    if (m_enemy_active) {
        m_game_state.enemies[0]->render(program);
    }

    if (m_key_spawned && !m_key_collected && m_key->is_active()) {
        m_key->render(program);
    }

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

        program->set_view_matrix(original_view_matrix);
    }
}
