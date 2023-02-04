#pragma once

#include <src/bird/BaseBird.hpp>

#include <memory>

class BirdMachine {
	public:
		//using BirdBuilder = std::function<std::shared_ptr<BaseBird>(BirdMachine*, float, float, float, float)>;

    	//BirdMachine(const std::initializer_list<std::pair<std::string, BirdBuilder>>& init_birds) noexcept;
		//Bird(BaseBird *_bird = nullptr);
		//Bird& operator = (BaseBird) = default;

		BirdMachine(std::shared_ptr<BaseBird> base = nullptr) noexcept;

    	//void change_bird(const std::string& state_name) noexcept;
		sf::FloatRect get_collision_rect() const noexcept;
	    void jump() noexcept;
		void update(float dt) noexcept;
		void render(sf::RenderTarget& target) const noexcept;
		void setBird(std::shared_ptr<BaseBird> base) noexcept;

		inline std::shared_ptr<BaseBird> get_base_bird() { return base_bird; }

	private:
		//std::unordered_map<std::string, BirdBuilder> birds;
    	//std::shared_ptr<BaseBird> current_bird{std::make_shared<BaseBird>(this)};

    	std::shared_ptr<BaseBird> base_bird;
};