/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Log.
*/

#include <Settings.hpp>
#include <src/Log.hpp>

Log::Log(float _x, float _y, bool _inverted) noexcept
    : x{_x}, y{_y}, inverted{_inverted}, sprite{Settings::textures["Log"]},
    /*x_original{_x},*/ y_original{_y}
{
    if (inverted)
    {
        sprite.rotate(180.f);
    }
}

sf::FloatRect Log::get_collision_rect() const noexcept
{
    if (!inverted)
    {
        return sf::FloatRect{x, y, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
    }

    return sf::FloatRect{x - Settings::LOG_WIDTH, y - Settings::LOG_HEIGHT, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
}

void Log::update_x(float _x) noexcept
{
    x = _x;

    if (inverted)
    {
        x += Settings::LOG_WIDTH;
    }

    sprite.setPosition(x, y);
}

void Log::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}

void Log::update_y(float speed/*, float stop*/) noexcept {
    if((approaching && inverted) || (!approaching && !inverted)) {
        y += speed;
    } else{
        y -= speed;
    }

    float collision = Settings::LOGS_GAP / 2;

    if(inverted) {
        if(y >= (y_original + collision)) {
            approaching = false;
            y = y_original + collision;
            Settings::sounds["wood"].play();

        } 

        if(y <= y_original) {
            approaching = true;
            y = y_original;
        }
    } else {
        if(y <= (y_original - collision)) {
            approaching = false;
            y = y_original - collision;
        } 

        if(y >= y_original) {
            approaching = true;
            y = y_original;
        }
    }

    sprite.setPosition(x, y);
}
