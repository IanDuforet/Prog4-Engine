#pragma once
#include "Singleton.h"
#include <unordered_map>


namespace elfgine
{
	class Observer;
	class ObserverManager : public elfgine::Singleton<ObserverManager>
	{
	public:
		void AddObserver(std::shared_ptr<Observer> pObserver, const std::string& observerName);
		std::shared_ptr<Observer> GetObserver(const std::string& observerName);
		
	private:
		std::unordered_map<std::string, std::shared_ptr<Observer>> m_pObservers;
	};
}

