#include "MiniginPCH.h"
#include "BaseComponent.h"

void elfgine::BaseComponent::AddGameObject(std::shared_ptr<GameObject> pGameobject)
{
	//Add a pointer to the gameobject in every component
	m_pGameObject = pGameobject;
}
