/**
* Author: Belinda Weng
* Assignment: your house
* Date due: 5/2/2025, 2:00pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "LevelB.h"
#include "Utility.h"

LevelB::LevelB() {
    unsigned int level_data[] = {
        128, 133, 80, 80, 80, 132, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 117,
        129, 97, 80, 80, 80, 96, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 97, 118,
        129, 112, 80, 80, 80, 103, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 93, 94, 118,
        129, 100, 80, 80, 80, 98, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 109, 110, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 80, 125, 126, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 80, 141, 142, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 118,
        129, 82, 80, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 80, 82, 80, 80, 80, 80, 118,
        115, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 130, 80, 80, 119, 114
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
    for (int i = 0; i < LEVEL2_WIDTH * LEVEL2_HEIGHT; i++) {
        LEVEL_2_DATA[i] = level_data[i];
        BACKGROUND_MAP_DATA[i] = background_data[i];
    }

    // Initialize pointers to nullptr
    m_game_state.player = nullptr;
    m_game_state.enemies = nullptr;
    m_game_state.map = nullptr;
    m_game_state.bgm = nullptr;
    m_game_state.jump_sfx = nullptr;
    m_game_state.next_scene_id = -1; 

    m_number_of_enemies = 3; 

    // Initialize enemy state
    m_enemy_active = false;
    m_enemy_following = false;
    m_enemy_timer = 0.0f;
    m_enemy_entry_position = glm::vec3(3.0f, -2.0f, 0.0f); 
}

LevelB::~LevelB() {
    // Clean up the enemies array
    if (m_game_state.enemies) {
        for (int i = 0; i < m_number_of_enemies; i++) {
            delete m_game_state.enemies[i];
        }
        delete[] m_game_state.enemies;
    }
}

void LevelB::initialise() {
    // MAP SET-UP
    GLuint map_texture_id = Utility::load_texture(MAP_TILESET_FILEPATH);

    // Create the background map first
    Map* background_map = new Map(LEVEL2_WIDTH, LEVEL2_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);

    // Create main map
    m_game_state.map = new Map(LEVEL2_WIDTH, LEVEL2_HEIGHT, LEVEL_2_DATA, map_texture_id, 1.0f, 16, 16);

    GLuint player_texture_id = Utility::load_texture(SPRITESHEET_FILEPATH);

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

    // Array of enemy pointers
    m_game_state.enemies = new Entity * [m_number_of_enemies];

    // Initialize each enemy
    for (int i = 0; i < m_number_of_enemies; i++) {
        m_game_state.enemies[i] = new Entity(
            enemy_texture_id,         // texture id
            5.0f,                     // speed - set directly here
            enemy_acceleration,       // acceleration
            3.0f,                     // jumping power
            enemy_walking_animation,  // animation index sets
            0.0f,                     // animation time
            3,                         // animation frame amount
            0,                         // current animation index
            6,                         // animation column amount
            6,                         // animation row amount
            0.9f,                      // width
            0.9f,                      // height
            ENEMY
        );

        // Set enemy AI type to GUARD and initial state to IDLE
        m_game_state.enemies[i]->set_entity_type(ENEMY);
        m_game_state.enemies[i]->set_ai_type(GUARD);
        m_game_state.enemies[i]->set_ai_state(IDLE);
        m_game_state.enemies[i]->face_down();
    }

    // Player starting position
    m_game_state.player->set_position(glm::vec3(17.0f, -13.0f, 0.0f));

    // Set different positions for each enemy
    m_game_state.enemies[0]->set_position(glm::vec3(9.0f, -5.0f, 0.0f));
    m_game_state.enemies[1]->set_position(glm::vec3(3.0f, -5.0f, 0.0f));
    m_game_state.enemies[2]->set_position(glm::vec3(4.0f, -5.0f, 0.0f));

    // Jumping
    m_game_state.player->set_jumping_power(5.0f);

    // Audio setup
    m_game_state.bgm = Mix_LoadMUS(BGM_FILEPATH);
    m_game_state.jump_sfx = Mix_LoadWAV(JUMP_SFX_FILEPATH);

    // Uncomment for music!!!!!!!!!!!!!!!!!!!!!
    // Mix_PlayMusic(m_game_state.bgm, -1);
    // Mix_VolumeMusic(MIX_MAX_VOLUME / 16.0f);
}

void LevelB::process_input() {
    if (m_game_frozen) {
        m_game_state.player->set_movement(glm::vec3(0.0f));
        return; 
    }

    m_game_state.player->set_movement(glm::vec3(0.0f));

    // Set default speed 
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

bool LevelB::check_collision_in_direction(Entity* entity, glm::vec3 direction) {
    // Check if there's a collision in the given direction
    glm::vec3 test_position = entity->get_position() + direction * 0.5f;

    // Create a probe point in the direction we're checking
    float penetration_x = 0;
    float penetration_y = 0;

    return m_game_state.map->is_solid(test_position, &penetration_x, &penetration_y);
}


void LevelB::update_enemy(float delta_time) {
    // If enemy is not active or game is frozen, don't update
    if (!m_enemy_active || m_game_frozen) {
        return;
    }

    // If enemy timer is active, count down
    if (m_enemy_timer > 0) {
        m_enemy_timer -= delta_time;
        if (m_enemy_timer <= 0) {
            // Timer expired, start following
            m_enemy_following = true;
            
            m_game_state.enemies[0]->set_position(m_enemy_entry_position);
            m_game_state.enemies[0]->activate();
        }
        return;
    }

    // If enemy is not following yet, don't move
    if (!m_enemy_following) {
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

void LevelB::check_player_enemy_collision() {
    // Check for collisions with each enemy
    for (int i = 0; i < m_number_of_enemies; i++) {
        if (m_game_state.enemies[i]->is_active() && m_game_state.enemies[i]->get_entity_type() == ENEMY) {
            // If player collides with an enemy, lose
            if (m_game_state.player->check_collision(m_game_state.enemies[i])) {
                m_game_state.next_scene_id = 2; 
                return; 
            }
        }
    }
}

void LevelB::update(float delta_time) {
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

    // Update all enemies
    for (int i = 0; i < m_number_of_enemies; i++) {
        // Only update active enemies
        if (m_game_state.enemies[i]->get_entity_type() == ENEMY && m_game_state.enemies[i]->is_active()) {
            m_game_state.enemies[i]->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
        }
    }

    // Update the chasing enemy if active
    update_enemy(delta_time);

    check_player_enemy_collision();
}

void LevelB::render(ShaderProgram* program) {
    m_game_state.map->render(program);

    m_game_state.player->render(program);

    // Render all enemies
    for (int i = 0; i < m_number_of_enemies; i++) {
        // Only render active enemies that are of type ENEMY
        if (m_game_state.enemies[i]->get_entity_type() == ENEMY && m_game_state.enemies[i]->is_active()) {
            m_game_state.enemies[i]->render(program);
        }
    }

    // Check if player is at the top of the level to go to Level C
    if (m_game_state.player->get_position().y >= -1.0f) {
        m_game_state.next_scene_id = 3;
    }

    // Check if player is at the bottom of the level to go back to Level A
    if (m_game_state.player->get_position().y <= -14.0f) {
        m_game_state.next_scene_id = 0;  
    }
}
