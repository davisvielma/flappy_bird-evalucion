#pragma once

#include <src/world/BaseWorld.hpp>

class NormalWorld : public BaseWorld {
	public:
		NormalWorld(bool _generate_logs = false) noexcept;
		
		void update(float dt) noexcept;
	    void render(sf::RenderTarget& target) const noexcept;
};