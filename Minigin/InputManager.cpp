#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


std::shared_ptr<elfgine::Command> elfgine::InputManager::ProcessInput()
{
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			m_Quit = true;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		if (e.type == SDL_SCANCODE_LEFT)
		{
			//return MoveLeft;
		}
		if (e.type == SDL_SCANCODE_A)
		{

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
	return nullptr;
}

bool elfgine::InputManager::HasQuit() const
{
	return m_Quit;
}


/*Process InputPlayer2
 *{
 *	bool m_hasJoined
 *	
 *	while
 *	{
 *		keyup{isJoined = true
 *				if(isJoined)
 *				}
 *		keydown{isJoined = true}
 *	}
 *
 *
 *}
 *
*/

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

