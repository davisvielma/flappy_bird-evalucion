/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class CountDownBaseState.
*/

#pragma once

#include <src/bird/BaseBird.hpp>
#include <src/world/BaseWorld.hpp>
#include <src/states/BaseState.hpp>

class CountDownState: public BaseState
{
public:
    CountDownState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<BaseWorld> _world = nullptr, std::shared_ptr<BaseBird> _bird = nullptr) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<BaseWorld> world;
    std::shared_ptr<BaseBird> bird;
    int counter{3};
    float timer{0.f};
};
