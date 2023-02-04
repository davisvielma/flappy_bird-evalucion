#pragma once

#include <SFML/Graphics.hpp>

class BirdMachine;

class BaseBird {
	public:
		BaseBird(float _x, float _y, float w, float h, bool mx);
		virtual ~BaseBird() { }

		sf::FloatRect get_collision_rect() const noexcept;
	    void jump() noexcept;

	    inline bool get_move_x() const { return move_x; }

	    virtual void reset() noexcept = 0;
		virtual void update(float dt) noexcept = 0;
		virtual void render(sf::RenderTarget& target) const noexcept = 0;
		virtual void speed_in_x(float speed) noexcept { }
	
	protected:
		float x;
	    float y;
	    float width;
	    float height;
	    float vy;
	    sf::Sprite sprite;
	    bool jumping{false};
	    bool move_x;
};