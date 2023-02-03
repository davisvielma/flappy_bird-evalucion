#pragma once

#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/states/BaseState.hpp>

class PauseState : public BaseState {
	private:
		std::shared_ptr<Bird> bird;
   		std::shared_ptr<World> world;

	public:
		PauseState(StateMachine* sm) noexcept;

		void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr) noexcept override;
	    void handle_inputs(const sf::Event& event) noexcept override;
	    void update(float dt) noexcept override;
	    void render(sf::RenderTarget& target) const noexcept override;
};