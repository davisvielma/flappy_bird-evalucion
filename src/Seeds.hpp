#pragma once

#include <Settings.hpp>

#include <SFML/Graphics.hpp>

class Seeds {
	private:
		float x;
		float y;
		float width;
		float height;
		sf::Sprite sprite;


	public:
		Seeds(float _x/* = -Settings::SEEDS_SIDE*/, float _y/* = 0*/) noexcept;

    	void update(float dt) noexcept;
		void render(sf::RenderTarget& target) const noexcept;
	    bool collides(const sf::FloatRect& rect) const noexcept;
		void reset(float _x, float _y) noexcept;	
    	bool is_out_of_game() const noexcept;
};