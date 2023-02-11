#pragma once

#include <src/world/BaseWorld.hpp>

class HardWorld: public BaseWorld {
	private:
		int count{0};
		Factory<Seeds> seeds_factory;
	    std::shared_ptr<Seeds> seeds;
	    float seeds_spawn_timer{0.f};

	public:
		HardWorld(bool _generate_logs = false) noexcept;
		
		void update(float dt) noexcept override;
	    void render(sf::RenderTarget& target) const noexcept override;
	    void reset(bool _generate_logs) noexcept override;
	    //bool collides(const sf::FloatRect& rect, bool power = false) const noexcept override;
	    bool seeds_collision(const sf::FloatRect& rect) noexcept override;
};