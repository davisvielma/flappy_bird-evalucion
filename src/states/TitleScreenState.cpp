/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>
#include <src/bird/NormalBird.hpp>

#include <iostream>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{ }
{
 
}

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
{
    if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
        option = false;
    }

    if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
        option = true;
    }

    if (event.key.code == sf::Keyboard::Enter)
    {

        if(!option) {
            std::shared_ptr<NormalBird> normalBird {
                std::make_shared<NormalBird>(
                    Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, 
                    Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
                    Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT
                )
            };
            
            bird_machine.setBird(normalBird);
        }

        state_machine->change_state("count_down", nullptr, bird_machine.get_base_bird());
    }
}

void TitleScreenState::update(float dt) noexcept
{
    world.update(dt);
}

void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, 
        "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3.5, 
        "> Normal", Settings::MEDIUM_TEXT_SIZE, "font", (!option ? sf::Color::Yellow : sf::Color::White), true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, 
        "> Hard", Settings::MEDIUM_TEXT_SIZE, "font", (option ? sf::Color::Yellow : sf::Color::White), true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 2.5, 
        "Choose an option and press Enter", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}