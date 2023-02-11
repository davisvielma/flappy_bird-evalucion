#include <src/bird/NormalBird.hpp>
#include <Settings.hpp>

NormalBird::NormalBird(float _x, float _y, float w, float h) noexcept : BaseBird {_x, _y, w, h, false} {
    
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

void NormalBird::reset() noexcept {
    x = ((Settings::VIRTUAL_WIDTH / 2) - (Settings::BIRD_WIDTH / 2));
    y = ((Settings::VIRTUAL_HEIGHT / 2) - (Settings::BIRD_HEIGHT / 2));
    vy = 0;
}
