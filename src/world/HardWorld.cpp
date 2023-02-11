#include <src/world/HardWorld.hpp>
#include <Settings.hpp>

HardWorld::HardWorld(bool _generate_logs) noexcept : BaseWorld{_generate_logs} {

}
		
void HardWorld::update(float dt) noexcept {
	if(!pause){
        if (generate_logs)
        {

            std::uniform_real_distribution<float> timer{1.3, 1.8};
            logs_spawn_timer += dt;
            seeds_spawn_timer += dt;

            if(seeds_spawn_timer >= Settings::SEEDS_TIME &&  logs_spawn_timer > 1.f && logs_spawn_timer < 1.2) {
                seeds_spawn_timer = 0.f;

                std::uniform_int_distribution<int> seeds_height{-4, 4};

                seeds = seeds_factory.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT / 2 + seeds_height(rng) * 10);
            }
        
            if (logs_spawn_timer >= (timer(rng) * 1.14))
            {
                logs_spawn_timer = 0.f;
        
                std::uniform_int_distribution<int> dist{-20, 20};
                float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(last_log_y + dist(rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));
        
                last_log_y = y;

                bool move = false;

                if(count % 2 != 0) {
                    move = true;
                }

                count++;
        
                logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y, move));
            } 
        }
        
        background_x += -Settings::BACK_SCROLL_SPEED * dt;
        
        if (background_x <= -Settings::BACKGROUND_LOOPING_POINT)
        {
            background_x = 0;
        }
        
        background.setPosition(background_x, 0);
        
        ground_x += -Settings::MAIN_SCROLL_SPEED * dt;
        
        if (ground_x <= -Settings::VIRTUAL_WIDTH)
        {
            ground_x = 0;
        }
        
        ground.setPosition(ground_x, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);
        
        for (auto it = logs.begin(); it != logs.end(); )
        {
            if ((*it)->is_out_of_game())
            {
                auto log_pair = *it;
                log_factory.remove(log_pair);
                it = logs.erase(it);
                    
            }
            else
            {
                (*it)->update(dt);
                ++it;
            }
        }

        if(seeds != nullptr) {
            if(seeds->is_out_of_game() ) {
                seeds_factory.remove(seeds);
                seeds = nullptr;
            } else {
                seeds->update(dt);
            }
        }
    }
}

void HardWorld::render(sf::RenderTarget& target) const noexcept {
	target.draw(background);

    for (const auto& log_pair: logs)
    {
        log_pair->render(target);
    }

    if(seeds != nullptr) {
        if(!seeds->is_out_of_game()) {
            seeds->render(target);
        }
    }

    target.draw(ground);
}

void HardWorld::reset(bool _generate_logs) noexcept {
    generate_logs = _generate_logs;

    for (auto it = logs.begin(); it != logs.end(); )
    {
        auto log_pair = *it;
        log_factory.remove(log_pair);
        it = logs.erase(it);           
    }

    seeds_spawn_timer = 0.f;

    if(seeds != nullptr) {
        seeds_factory.remove(seeds);
        seeds = nullptr;
    }
}

/*bool HardWorld::collides(const sf::FloatRect& rect, bool power) const noexcept
{
    if (rect.top + rect.height >= Settings::VIRTUAL_HEIGHT || rect.top <= 0)
    {
        return true;
    }
    
    if(!power) {
        for (auto log_pair: logs)
        {
            if (log_pair->collides(rect))
            {
                return true;
            }
        }
    }

    return false;
}*/

bool HardWorld::seeds_collision(const sf::FloatRect& rect) noexcept {
    if(seeds != nullptr) {
        if(seeds->collides(rect)) {
            seeds_spawn_timer = 0.f;
            seeds_factory.remove(seeds);
            seeds = nullptr;

            return true;
        }
    }

    return false;
}