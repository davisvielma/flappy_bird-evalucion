#include <src/bird/BirdMachine.hpp>
#include <Settings.hpp>

BirdMachine::BirdMachine(std::shared_ptr<BaseBird> base) noexcept : 
	base_bird{base} {

}

sf::FloatRect BirdMachine::get_collision_rect() const noexcept {
	return base_bird->get_collision_rect();
}

void BirdMachine::jump() noexcept {
	base_bird->jump();
}

void BirdMachine::update(float dt) noexcept {
	base_bird->update(dt);
}

void BirdMachine::render(sf::RenderTarget& target) const noexcept {
	base_bird->render(target);
}

void BirdMachine::setBird(std::shared_ptr<BaseBird> base) noexcept {
	base_bird = base;
}
