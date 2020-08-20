#include "MiniginPCH.h"
#include "BaseComponent.h"

void elfgine::BaseComponent::AddGameObject(std::weak_ptr<GameObject> pGameobject)
{
	//Add a pointer to the gameobject in every component
	m_pGameObject = pGameobject;
}
