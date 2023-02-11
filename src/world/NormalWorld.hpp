#pragma once

#include <src/world/BaseWorld.hpp>

class NormalWorld : public BaseWorld {
	public:
		NormalWorld(bool _generate_logs = false) noexcept;
		
		void update(float dt) noexcept override;
	    void render(sf::RenderTarget& target) const noexcept override;
	    void reset(bool _generate_logs) noexcept override;
	    //bool collides(const sf::FloatRect& rect, bool power = false) const noexcept override;
};