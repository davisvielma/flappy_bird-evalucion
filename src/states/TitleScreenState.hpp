/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class TitleScreenState.
*/

#pragma once

#include <src/states/BaseState.hpp>
#include <src/bird/BirdMachine.hpp>
#include <src/world/WorldMachine.hpp>

class TitleScreenState : public BaseState
{
public:
    TitleScreenState(StateMachine* sm) noexcept;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    WorldMachine world_machine;
    std::shared_ptr<BaseWorld> world;
    BirdMachine bird_machine;
    bool option{false};
};
