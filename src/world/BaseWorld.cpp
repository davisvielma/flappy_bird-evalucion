#include <Settings.hpp>
#include <src/world/BaseWorld.hpp>

BaseWorld::BaseWorld(bool _generate_logs)
    : generate_logs{_generate_logs}, background{Settings::textures["background"]}, ground{Settings::textures["ground"]},
      logs{}, rng{std::default_random_engine{}()}
{
    ground.setPosition(0, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);
    std::uniform_int_distribution<int> dist(0, 80);
    last_log_y = -Settings::LOG_HEIGHT + dist(rng) + 20;
}

bool BaseWorld::update_scored(const sf::FloatRect& rect) noexcept
{
    for (auto log_pair: logs)
    {
        if (log_pair->update_scored(rect))
        {
            return true;
        }
    }

    return false;
}

void BaseWorld::setPause() noexcept {
    pause = !pause;
}

bool BaseWorld::collides(const sf::FloatRect& rect, bool power) const noexcept
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
}