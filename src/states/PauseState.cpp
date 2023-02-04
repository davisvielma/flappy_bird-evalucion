#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm) noexcept : BaseState{sm} {

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<BaseBird> _bird) noexcept {
	world = _world;
	bird = _bird;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept {
    if (event.key.code == sf::Keyboard::P) {
        state_machine->change_state("playing", world, bird);
    }
}

void PauseState::update(float dt) noexcept {
    world->update(dt);
}

void PauseState::render(sf::RenderTarget& target) const noexcept {
    world->render(target);
    bird->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Pause", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press P to continue", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}