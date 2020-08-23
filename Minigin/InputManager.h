#pragma once
#include <XInput.h>
#include "Singleton.h"
#include <vector>
#include "Command.h"

namespace elfgine
{
	class Command;
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY,
		DPADLeft,
		DPADRight,
		DPADUp,
		DPADDown
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		std::shared_ptr<Command> ProcessInput();
		std::shared_ptr<Command> ProcessContinuous();
		bool HasQuit() const;
		bool IsPressed(ControllerButton button) const;
	private:
		XINPUT_STATE m_CurrentState{};
		std::shared_ptr<MoveLeft> m_pMoveLeft{std::make_shared<MoveLeft>()};
		std::shared_ptr<MoveUp> m_pMoveUp{ std::make_shared<MoveUp>() };
		std::shared_ptr<MoveRight> m_pMoveRight{ std::make_shared<MoveRight>() };
		std::shared_ptr<MoveDown> m_pMoveDown{ std::make_shared<MoveDown>() };
		std::shared_ptr<Shoot> m_Shoot{ std::make_shared<Shoot>() };
		bool m_Quit{false};
	};

}
