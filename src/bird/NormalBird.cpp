#include <src/bird/NormalBird.hpp>
#include <Settings.hpp>
#include <iostream>

NormalBird::NormalBird(float _x, float _y, float w, float h) noexcept : BaseBird {_x, _y, w, h} {
    
}

void NormalBird::update(float dt) noexcept {
	vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    y += vy * dt;
    sprite.setPosition(x, y);
}

void NormalBird::render(sf::RenderTarget& target) const noexcept {
	target.draw(sprite);
}
