/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>

#include <iostream>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}, power_time{Settings::POWER_TIME}
{

}

void PlayingState::enter(std::shared_ptr<BaseWorld> _world, std::shared_ptr<BaseBird> _bird) noexcept
{
    world = _world;

    if(world->getPause()) {
        world->setPause();
    } else {
        world->reset(true);
    }
    
    bird = _bird;
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        world->setPause();
        state_machine->change_state("pause", world, bird);
    }

    if(bird->get_move_x() && event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
            bird->speed_in_x(-Settings::BIRD_SPEED);
        } else if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
            bird->speed_in_x(Settings::BIRD_SPEED);
        } else {
            bird->speed_in_x(0.f);
        }
    }
}

void PlayingState::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    if(power_time == 0) {
        power_time = Settings::POWER_TIME;
        bird->set_power();
        bird->set_texture(Settings::textures["bird"]);
    }

    if (world->collides(bird->get_collision_rect(), bird->get_power()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        bird->reset();
        world->reset(false);
        state_machine->change_state("count_down", world, bird);
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        ++score;
        Settings::sounds["score"].play();
    }

    if(world->seeds_collision(bird->get_collision_rect())) {
        std::cout << "Colisiono el pajaro con la semilla" << std::endl;
        bird->set_power();
        bird->set_texture(Settings::textures["ghost"]);
    }

    if(bird->get_power()) {
        timer += dt;

        if (timer > 1.f) {
            power_time--;
            timer = 0;
        }
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);

    if(bird->get_power()) {
        render_text(target, 20, 40, "Power time: " + std::to_string(power_time), Settings::MEDIUM_TEXT_SIZE, "flappy", sf::Color::White);
    }
}