#include <src/world/WorldMachine.hpp>
#include <Settings.hpp>

WorldMachine::WorldMachine(std::shared_ptr<BaseWorld> base ) noexcept : base_world{base} {

}

void WorldMachine::setWorld(std::shared_ptr<BaseWorld> base) noexcept {
	base_world = base;
}