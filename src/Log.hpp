/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Log.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Log
{
public:
    Log(float _x, float _y, bool inverted) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    void update_x(float _x) noexcept;
    void update_y(float speed/*, float stop*/) noexcept;
    void render(sf::RenderTarget& target) const noexcept;


private:
    float x;
    float y;
    float y_original;
    //float x_original;
    bool inverted;
    bool approaching{true};
    sf::Sprite sprite;
};