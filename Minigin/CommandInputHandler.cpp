#include "MiniginPCH.h"
#include "CommandInputHandler.h"
#include "Command.h"
#include "InputManager.h"

//Command* received;
//do
//{
//	received = inputmanager::Provess();
//	if(received)
//		reveided.execute(controlcomponent);
//		
//} while(received);
//

elfgine::CommandInputHandler::CommandInputHandler()
	: Singleton<elfgine::CommandInputHandler>()
    , m_pManager(InputManager::GetInstance())
{
	
}


void elfgine::CommandInputHandler::AssignActor(std::shared_ptr<ControlComponent> pControlComponent)
{
	m_pControlPlayer1 = pControlComponent;
}

void elfgine::CommandInputHandler::HandleCommands()
{
	std::shared_ptr<Command> pReceived;
	do
	{
		pReceived = m_pManager.ProcessInput();
		if (pReceived)
			pReceived->execute(m_pControlPlayer1);
	} while (pReceived);
}

void elfgine::CommandInputHandler::HandleContinuous()
{
	std::shared_ptr<Command> pReceived;
	pReceived = m_pManager.ProcessContinuous();
	if (pReceived)
		pReceived->execute(m_pControlPlayer1);
}
