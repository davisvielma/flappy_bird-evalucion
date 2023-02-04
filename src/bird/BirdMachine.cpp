#include <src/bird/BirdMachine.hpp>
#include <Settings.hpp>

#include <iostream>

BirdMachine::BirdMachine(std::shared_ptr<BaseBird> base) noexcept : 
	base_bird{base} {

}

/*void BirdMachine::change_bird(const std::string& bird_name) noexcept {
	auto it = birds.find(bird_name);

    if (it == birds.end())
    {
        return;
    }

    float x = Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2; 
    float y = Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,

    current_bird = it->second(this, x, y, Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT);

    return current_bird;
}*/


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
