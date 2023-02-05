#pragma once

#include <src/world/BaseWorld.hpp>

#include <memory>

class WorldMachine {
	private:
		std::shared_ptr<BaseWorld> base_world;

	public:
		WorldMachine(std::shared_ptr<BaseWorld> base = nullptr) noexcept;

		void setWorld(std::shared_ptr<BaseWorld> base) noexcept;

		inline std::shared_ptr<BaseWorld> get_base_world() { return base_world; }
};
