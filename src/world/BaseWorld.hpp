#pragma once

#include <list>
#include <memory>
#include <random>

#include <SFML/Graphics.hpp>

#include <src/Factory.hpp>
#include <src/LogPair.hpp>

class BaseWorld {
	protected:
		bool generate_logs;

	    sf::Sprite background;
	    sf::Sprite ground;

	    float background_x{0.f};
	    float ground_x{0.f};

	    Factory<LogPair> log_factory;

	    std::list<std::shared_ptr<LogPair>> logs;

	    std::mt19937 rng;

	    float logs_spawn_timer{0.f};
	    float last_log_y{0.f};

    	bool pause{false};

	public:
		BaseWorld(bool _generate_logs = false);
		virtual ~BaseWorld() { }
	
	    bool collides(const sf::FloatRect& rect) const noexcept;
	    bool update_scored(const sf::FloatRect& rect) noexcept;
	    void setPause() noexcept;
		void reset(bool _generate_logs) noexcept;

	    inline bool getPause() const { return pause; }

	    virtual void update(float dt) noexcept = 0;
	    virtual void render(sf::RenderTarget& target) const noexcept = 0;
};