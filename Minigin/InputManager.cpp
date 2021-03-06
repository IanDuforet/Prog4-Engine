#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


std::shared_ptr<elfgine::Command> elfgine::InputManager::ProcessInput()
{
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
			m_Quit = true;
			break;
		case SDL_KEYDOWN:
			if(e.key.keysym.sym == SDLK_SPACE)
				return m_pShoot;
		}
	}

	
	
	return nullptr;
}

std::shared_ptr<elfgine::Command> elfgine::InputManager::ProcessContinuous()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_LEFT]) {
		return m_pMoveLeft;
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		return m_pMoveRight;
	}
	if (state[SDL_SCANCODE_UP]) {
		return m_pMoveUp;
	}
	if (state[SDL_SCANCODE_DOWN]) {
		return m_pMoveDown;
	}
	if(IsPressed(ControllerButton::DPADLeft))
	{
		return m_pMoveLeft;
	}
	if (IsPressed(ControllerButton::DPADRight))
	{
		return m_pMoveRight;
	}
	if (IsPressed(ControllerButton::DPADUp))
	{
		return m_pMoveUp;
	}
	if (IsPressed(ControllerButton::DPADDown))
	{
		return m_pMoveDown;
	}
	if (IsPressed(ControllerButton::ButtonA))
	{
		return m_pShoot;
	}
	return nullptr;
}

bool elfgine::InputManager::HasQuit() const
{
	return m_Quit;
}


bool elfgine::InputManager::IsPressed(ControllerButton button) const
{
	
	switch (button)
	{
	case ControllerButton::ButtonA:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	case ControllerButton::DPADLeft:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
	case ControllerButton::DPADRight:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
	case ControllerButton::DPADUp:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
	case ControllerButton::DPADDown:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
	default: return false;
	}
}

