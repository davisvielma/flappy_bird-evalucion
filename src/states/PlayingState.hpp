/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class PlayingBaseState.
*/

#pragma once

#include <src/bird/BaseBird.hpp>
#include <src/world/BaseWorld.hpp>
#include <src/states/BaseState.hpp>

class PlayingState: public BaseState
{

public:
    PlayingState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<BaseWorld> _world = nullptr, std::shared_ptr<BaseBird> _bird = nullptr) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<BaseBird> bird;
    std::shared_ptr<BaseWorld> world;
    int score{0};
    float timer{0.f};
    int power_time;
};
