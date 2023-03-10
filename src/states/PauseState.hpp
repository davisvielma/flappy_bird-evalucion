#pragma once

#include <src/bird/BaseBird.hpp>
#include <src/world/BaseWorld.hpp>
#include <src/states/BaseState.hpp>

class PauseState : public BaseState {
	private:
		std::shared_ptr<BaseBird> bird;
   		std::shared_ptr<BaseWorld> world;

	public:
		PauseState(StateMachine* sm) noexcept;

		void enter(std::shared_ptr<BaseWorld> _world = nullptr, std::shared_ptr<BaseBird> _bird = nullptr) noexcept override;
	    void handle_inputs(const sf::Event& event) noexcept override;
	    void update(float dt) noexcept override;
	    void render(sf::RenderTarget& target) const noexcept override;
};