#pragma once

#include <src/bird/BaseBird.hpp>

class NormalBird : public BaseBird {
	public:
		NormalBird(float _x, float _y, float w, float h) noexcept;

	 	void update(float dt) noexcept override;
		void render(sf::RenderTarget& target) const noexcept override;
		void reset() noexcept override;
};