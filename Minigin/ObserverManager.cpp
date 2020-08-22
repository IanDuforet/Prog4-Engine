#include "MiniginPCH.h"
#include "ObserverManager.h"
#include "Observer.h"
void elfgine::ObserverManager::AddObserver(std::shared_ptr<Observer> pObserver, const std::string& observerName)
{
	std::pair<std::string, std::shared_ptr<Observer>> Pair(observerName, pObserver);
	m_pObservers.insert(Pair);
}

std::shared_ptr<elfgine::Observer> elfgine::ObserverManager::GetObserver(const std::string& observerName)
{
	return m_pObservers.at(observerName);
}
