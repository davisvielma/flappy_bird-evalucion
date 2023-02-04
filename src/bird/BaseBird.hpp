#pragma once

#include <SFML/Graphics.hpp>

class BirdMachine;

class BaseBird {
	public:
		BaseBird(float _x, float _y, float w, float h);
		virtual ~BaseBird() { }

		sf::FloatRect get_collision_rect() const noexcept;
	    void jump() noexcept;

		virtual void update(float dt) noexcept = 0;
	
		virtual void render(sf::RenderTarget& target) const noexcept = 0;
	
	protected:
		float x;
	    float y;
	    float width;
	    float height;
	    float vy;
	    sf::Sprite sprite;
	    bool jumping{false};

	    //BirdMachine *bird_machine;
};