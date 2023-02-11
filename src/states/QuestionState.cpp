#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/QuestionState.hpp>

QuestionState::QuestionState(StateMachine* sm) noexcept : BaseState{sm} {

}

void QuestionState::enter(std::shared_ptr<BaseWorld> _world, std::shared_ptr<BaseBird> _bird) noexcept {
	world = _world;
	bird = _bird;
}

void QuestionState::handle_inputs(const sf::Event& event) noexcept {
    if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
        option = false;
    }

    if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
        option = true;
    }

    if (event.key.code == sf::Keyboard::Enter)
    {

        if(option) {
            /*world = nullptr;
            bird = nullptr; */
            state_machine->change_state("title"/*, world, bird*/);
        } else {
            state_machine->change_state("count_down", world, bird);
        }

    }
}

void QuestionState::update(float dt) noexcept {
    world->update(dt);
}

void QuestionState::render(sf::RenderTarget& target) const noexcept {
    world->render(target);
     render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, 
        "Do yo want continue this mode?", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3.5, 
        "> Yes", Settings::MEDIUM_TEXT_SIZE, "font", (!option ? sf::Color::Yellow : sf::Color::White), true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, 
        "> No", Settings::MEDIUM_TEXT_SIZE, "font", (option ? sf::Color::Yellow : sf::Color::White), true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 2.5, 
        "Choose an option and press Enter", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}