#pragma once

#include <src/bird/BaseBird.hpp>

class HardBird : public BaseBird {
	private:
		float vx;
		bool displacement{false};

	public:
		HardBird(float _x, float _y, float w, float h) noexcept;

		void update(float dt) noexcept override;
		void reset() noexcept override;	
		void speed_in_x(float speed) noexcept override;
		void set_texture(sf::Texture &texture) noexcept override;
};