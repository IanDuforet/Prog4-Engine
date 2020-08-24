#pragma once
#include "Singleton.h"

namespace elfgine
{
	class ControlComponent;
	class InputManager;
	class CommandInputHandler final : public Singleton<CommandInputHandler>
	{
	public:
		CommandInputHandler();
		virtual ~CommandInputHandler() = default;
		CommandInputHandler(const CommandInputHandler& other) = delete;
		CommandInputHandler(CommandInputHandler&& other) = delete;
		CommandInputHandler& operator=(const CommandInputHandler& other) = delete;
		CommandInputHandler& operator=(CommandInputHandler&& other) = delete;

		//Functions
		void AssignActor(std::shared_ptr<ControlComponent> pControlComponent);
		void HandleCommands();
		void HandleContinuous();
	private:
		//Variables
		InputManager& m_pManager;
		std::weak_ptr<ControlComponent> m_pControlPlayer1;
	};
}

