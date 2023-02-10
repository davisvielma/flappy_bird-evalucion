#include <src/Seeds.hpp>

Seeds::Seeds(float _x, float _y) noexcept : x{_x}, y{_y}, 
	width{Settings::SEEDS_SIDE}, height{Settings::SEEDS_SIDE}, sprite{Settings::textures["seeds"]} {

}

void Seeds::update(float dt) noexcept {
	x += -Settings::MAIN_SCROLL_SPEED * dt;

	sprite.setPosition(x, y);
}

void Seeds::render(sf::RenderTarget& target) const noexcept {
    target.draw(sprite);
}

bool Seeds::collides(const sf::FloatRect& rect) const noexcept {
	sf::FloatRect seeds_rec = get_collision_rect();

	return seeds_rec.intersects(rect);
}

void Seeds::reset(float _x, float _y) noexcept {
	x = _x;
    y = _y;
}

bool Seeds::is_out_of_game() const noexcept {
    return x < -Settings::SEEDS_SIDE;
}

sf::FloatRect Seeds::get_collision_rect() const noexcept {
	return sf::FloatRect{x, y, width, height};
}