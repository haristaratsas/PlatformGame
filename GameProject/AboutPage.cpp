#include <sgg/graphics.h>
#include "AboutPage.h"
#include "util.h"
#include <string>
#include "gamestate.h"
#include <iostream>

// Constructor
AboutPage::AboutPage() {
    // Set the object as active
    this->GameObject::setActive(true);

    // Initialize position and dimensions based on canvas size
    m_width = GameState::getInstance()->getCanvasWidth();
    m_height = GameState::getInstance()->getCanvasHeight();
    m_pos_x = GameState::getInstance()->getCanvasWidth() / 2.0f;
    m_pos_y = GameState::getInstance()->getCanvasHeight() / 2.0f;
}

// Destructor
AboutPage::~AboutPage() {

}

// Initialize method
void AboutPage::init() {
    // Set up background texture and properties
    brush_about_background.texture = m_state->getFullAssetPath("backgroundmenu.png");
    brush_about_background.outline_opacity = 0.0f;

    // Set up text properties
    SETCOLOR(brush_about_text.fill_color, 0, 0, 0);
    brush_about_text.outline_opacity = 0.0f;
    SETCOLOR(brush_about_text2.fill_color, 1.f, 1.f, 1.f);

    // Set up information text about the game
    about_text1 = "Starchaser's Odyssey is a game where the player's goal is to collect all stars";
    about_text2 = " and find the escape door. Throughout the level, the player comes across some ";
    about_text3 = "obstacle courses and enemies, who he must kill, in order to collect some stars.";
    about_text4 = "The player can move with the WASD keys and attack with the left mouse button.";

    // Set up textures for additional information
    brush_wasd.texture = m_state->getFullAssetPath("wasd3.png");
    brush_wasd.outline_opacity = 0.0f;

    brush_left_click.texture = m_state->getFullAssetPath("left_click.png");
    brush_left_click.outline_opacity = 0.0f;
}

// Draw method
void AboutPage::draw() {
    // Draw the background and the text
    graphics::setFont(m_state->getFullAssetPath("ThaleahFat.ttf"));
    graphics::drawText(0.7f, 0.7f, 0.45, about_text1, brush_about_text);
    graphics::drawText(0.7f, 1.0f, 0.45, about_text2, brush_about_text);
    graphics::drawText(0.7f, 1.3f, 0.45, about_text3, brush_about_text);
    graphics::drawText(0.7f, 1.6f, 0.45, about_text4, brush_about_text);
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, brush_about_background);

    // Draw WASD and left click information
    float wasd_pos_x = 5.5;
    float wasd_pos_y = m_height - 2.0;
    graphics::drawRect(wasd_pos_x, wasd_pos_y, 4.0f, 4.0f, brush_wasd);

    float left_click_pos_x = m_width - 4.5;
    float left_click_pos_y = m_height - 2.0;
    graphics::drawRect(left_click_pos_x, left_click_pos_y, 3.0f, 3.0f, brush_left_click);

    // Draw information about the creators
    graphics::drawText(0.2f, 2.5f, 0.6, "Creators of the game:", brush_about_text);
    graphics::drawText(0.2f, 3.0f, 0.6, "Dimitrakopoulos Zois Athanasios.", brush_about_text);
    graphics::drawText(0.2f, 3.5f, 0.6, "Lampos Andreas.", brush_about_text);
    graphics::drawText(0.2f, 4.0f, 0.6, "Taratsas Haralampos.", brush_about_text);
    graphics::drawText(3.0f, 5.8f, 0.6, "  This is how you move.              This is how you attack.", brush_about_text2);
    graphics::drawText(3.5f, 9.9f, 0.5f, "Press backspace to go back to the main menu", brush_about_text2);
}

// Update method
void AboutPage::update(float dt) {

    // Check if the backspace key is pressed to go back to the main menu
    if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {
        graphics::playSound(m_state->getFullAssetPath("optionselected.wav"), 0.5f);
        GameState::getInstance()->switchToMenu();
    }
}
