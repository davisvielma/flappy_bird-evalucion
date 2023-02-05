/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class CountDownBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/CountDownState.hpp>

CountDownState::CountDownState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void CountDownState::enter(std::shared_ptr<BaseWorld> _world, std::shared_ptr<BaseBird> _bird) noexcept
{
    world = _world;
    bird = _bird;
}

void CountDownState::update(float dt) noexcept
{
    timer += dt;

    if (timer >= 1.f)
    {
        timer = 0.f;
        --counter;

        if (counter == 0)
        {
            state_machine->change_state("playing", world, bird);
        }
    }

    world->update(dt);
}

void CountDownState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2.5, 
        std::to_string(counter), Settings::HUGE_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 1.5, 
        "Presione P to pause the game", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}