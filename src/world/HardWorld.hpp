#pragma once

#include <src/world/BaseWorld.hpp>

class HardWorld: public BaseWorld {
	private:
		int count{0};

	public:
		HardWorld(bool _generate_logs = false) noexcept;
		
		void update(float dt) noexcept override;
	    void render(sf::RenderTarget& target) const noexcept override;
	    void reset(bool _generate_logs) noexcept override;
};