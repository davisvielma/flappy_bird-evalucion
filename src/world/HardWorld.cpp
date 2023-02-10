#include <src/world/HardWorld.hpp>
#include <Settings.hpp>
#include <iostream>

HardWorld::HardWorld(bool _generate_logs) noexcept : BaseWorld{_generate_logs} {

}
		
void HardWorld::update(float dt) noexcept {
	if(!pause){
        if (generate_logs)
        {

            std::uniform_real_distribution<float> timer{1.4, 2.0};
            logs_spawn_timer += dt;

            //float prueba = timer(rng) * 1.14;
        
            if (logs_spawn_timer >= (timer(rng) * 1.14) /*Settings::TIME_TO_SPAWN_LOGS*/)
            {
                /*std::cout << "el valor de lst: " << logs_spawn_timer << std::endl;
                std::cout << "el valor de timer: " << prueba << std::endl;
*/
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
    }
}

void HardWorld::render(sf::RenderTarget& target) const noexcept {
	target.draw(background);

    for (const auto& log_pair: logs)
    {
        log_pair->render(target);
    }

    target.draw(ground);
}