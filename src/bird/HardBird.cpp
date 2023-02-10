#include <src/bird/HardBird.hpp>
#include <Settings.hpp>

HardBird::HardBird(float _x, float _y, float w, float h) noexcept : BaseBird {_x, _y, w, h, true}, vx {0.f} {

}

void HardBird::update(float dt) noexcept {
	vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    if(displacement) {
    	x += vx * dt;
    	displacement = false;
    }

    y += vy * dt;

    if(x <= 0) {
        x = 0;
    }

    if((x + width) >= Settings::VIRTUAL_WIDTH) {
        x = Settings::VIRTUAL_WIDTH - Settings::BIRD_WIDTH;
    }

    sprite.setPosition(x, y);
}

void HardBird::render(sf::RenderTarget& target) const noexcept {
	target.draw(sprite);
}

void HardBird::reset() noexcept {
    x = ((Settings::VIRTUAL_WIDTH / 2) - (Settings::BIRD_WIDTH / 2));
    y = ((Settings::VIRTUAL_HEIGHT / 2) - (Settings::BIRD_HEIGHT / 2));
    vy = 0;
    vx = 0;
    power = false;
    set_texture(Settings::textures["bird"]);
}

void HardBird::speed_in_x(float speed) noexcept {
	displacement = true;
	vx = speed;
}

void HardBird::set_texture(sf::Texture &texture) noexcept {
    sprite.setTexture(texture);
}