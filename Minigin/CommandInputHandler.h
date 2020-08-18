#pragma once
#include "Singleton.h"

namespace elfgine
{
	class ControlComponent;
	class InputManager;
	class CommandInputHandler : public Singleton<CommandInputHandler>
	{
	public:
		CommandInputHandler();
		void AssignActor(std::shared_ptr<ControlComponent> pControlComponent);
		void HandleCommands();
		void HandleContinuous();
	private:
		InputManager& m_pManager;
		std::weak_ptr<ControlComponent> m_pControlPlayer1;
	};
}

