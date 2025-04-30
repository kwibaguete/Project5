#include "LevelC.h"
#include "Utility.h"

LevelC::LevelC() {
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
    for (int i = 0; i < LEVEL3_WIDTH * LEVEL3_HEIGHT; i++) {
        LEVEL_3_DATA[i] = level_data[i];
        BACKGROUND_MAP_DATA[i] = background_data[i];
    }

    // Initialize pointers to nullptr
    m_game_state.player = nullptr;
    m_game_state.enemies = nullptr;
    m_game_state.map = nullptr;
    m_game_state.bgm = nullptr;
    m_game_state.jump_sfx = nullptr;
    m_game_state.next_scene_id = -1; // Initialize to -1, meaning no scene change

    // Set the number of enemies for this level
    m_number_of_enemies = 3; // We'll create 3 enemies
}

LevelC::~LevelC() {
    // Clean up the enemies array
    if (m_game_state.enemies) {
        for (int i = 0; i < m_number_of_enemies; i++) {
            delete m_game_state.enemies[i];
        }
        delete[] m_game_state.enemies;
    }
}

void LevelC::initialise() {
    // MAP SET-UP
    GLuint map_texture_id = Utility::load_texture(MAP_TILESET_FILEPATH);

    // Create the background map first
    Map* background_map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, BACKGROUND_MAP_DATA, map_texture_id, 1.0f, 16, 16);

    // Then create the main map with all the visible elements
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

    // Create an array of enemy pointers
    m_game_state.enemies = new Entity * [m_number_of_enemies];

    // Initialize each enemy
    for (int i = 0; i < m_number_of_enemies; i++) {
        m_game_state.enemies[i] = new Entity(
            enemy_texture_id,         // texture id
            3.0f,                     // speed - set directly here
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

    // Set player starting position
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

void LevelC::process_input() {
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

void LevelC::update(float delta_time) {
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

    // Update all enemies
    for (int i = 0; i < m_number_of_enemies; i++) {
        // Only update active enemies
        if (m_game_state.enemies[i]->get_entity_type() == ENEMY) {
            m_game_state.enemies[i]->update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
        }
    }
}

void LevelC::render(ShaderProgram* program) {
    // Render in layers: background first, then main map, then entities
    m_game_state.map->render(program);

    // Render the player
    m_game_state.player->render(program);

    // Render all enemies
    for (int i = 0; i < m_number_of_enemies; i++) {
        // Only render active enemies that are of type ENEMY
        if (m_game_state.enemies[i]->get_entity_type() == ENEMY && m_game_state.enemies[i]->is_active()) {
            m_game_state.enemies[i]->render(program);
        }
    }
}
