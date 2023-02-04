#pragma once

#include <src/bird/BaseBird.hpp>

#include <memory>

class BirdMachine {
	public:
		BirdMachine(std::shared_ptr<BaseBird> base = nullptr) noexcept;

		sf::FloatRect get_collision_rect() const noexcept;
	    void jump() noexcept;
		void update(float dt) noexcept;
		void render(sf::RenderTarget& target) const noexcept;
		void setBird(std::shared_ptr<BaseBird> base) noexcept;

		inline std::shared_ptr<BaseBird> get_base_bird() { return base_bird; }

	private:
		std::shared_ptr<BaseBird> base_bird;
};