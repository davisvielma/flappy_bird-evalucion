#include <src/bird/BaseBird.hpp>
#include <Settings.hpp>

BaseBird::BaseBird(float _x, float _y, float w, float h, bool mx) : x{_x}, y{_y}, 
	width{w},height{h}, move_x{mx}, vy{0.f}, sprite{Settings::textures["bird"]} {

	sprite.setPosition(x, y);
}

sf::FloatRect BaseBird::get_collision_rect() const noexcept {
    return sf::FloatRect{x, y, width, height};
}

void BaseBird::jump() noexcept {
    if (!jumping)
    {
        jumping = true;
    }
}

void BaseBird::set_power() noexcept {
    power = !power;
}