/**
* Author: Belinda Weng
* Assignment: your house
* Date due: 5/2/2025, 2:00pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "LoseScene.h"
#include "Utility.h"

LoseScene::LoseScene() {
    lose_message = "YOU DIED";
    restart_prompt = "PRESS Q TO EXIT";
}

void LoseScene::initialise() {
    font_texture_id = Utility::load_texture("assets/font1.png");

    m_game_state.next_scene_id = -1;
}

void LoseScene::update(float delta_time) {
    // Nothing to update in the lose scene
}

void LoseScene::render(ShaderProgram* program) {
    glm::mat4 view_matrix = glm::mat4(1.0f);
    program->set_view_matrix(view_matrix);

    // Render the lose message 
    Utility::draw_text(program, font_texture_id, lose_message, 0.4f, 0.2f, glm::vec3(-4.0f, 2.0f, 0.0f));

    // Render the restart prompt 
    Utility::draw_text(program, font_texture_id, restart_prompt, 0.25f, 0.15f, glm::vec3(-4.0f, 0.0f, 0.0f));
}