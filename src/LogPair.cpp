/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class LogPair.
*/

#include <Settings.hpp>
#include <src/LogPair.hpp>
#include <iostream>

LogPair::LogPair(float _x, float _y, bool _move) noexcept
    : x{_x}, y{_y}, move{_move}, 
      top{x, y + Settings::LOG_HEIGHT, true},
      bottom{x, y + Settings::LOGS_GAP + Settings::LOG_HEIGHT, false}
{
    
}

bool LogPair::collides(const sf::FloatRect& rect) const noexcept
{
    return top.get_collision_rect().intersects(rect) || bottom.get_collision_rect().intersects(rect);
}

void LogPair::update(float dt) noexcept
{
    x += -Settings::MAIN_SCROLL_SPEED * dt;

    std::uniform_int_distribution<int> dist{0, 10};

    if(move) {
        float position = Settings::LOGS_SPEED * dt;

        top.update_y(position);
        bottom.update_y(position);
    }

    top.update_x(x);
    bottom.update_x(x);
}

void LogPair::render(sf::RenderTarget& target) const noexcept
{
    top.render(target);
    bottom.render(target);
}

bool LogPair::is_out_of_game() const noexcept
{
    return x < -Settings::LOG_WIDTH;
}

bool LogPair::update_scored(const sf::FloatRect& rect) noexcept
{
    if (scored)
    {
        return false;
    }

    if (rect.left > x + Settings::LOG_WIDTH)
    {
        scored = true;
        return true;
    }

    return false;
}

void LogPair::reset(float _x, float _y, bool _move) noexcept
{
    x = _x;
    y = _y;
    scored = false;
    move = _move;
    top.position_reset_y();
    bottom.position_reset_y();
}

void LogPair::setMove() noexcept
{
    move = !move;
}