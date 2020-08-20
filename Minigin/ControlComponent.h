#pragma once
#include "BaseComponent.h"
namespace elfgine
{
	class RigidBodyComponent;
	class ControlComponent :
		public BaseComponent
	{
	public:
		ControlComponent(std::shared_ptr<RigidBodyComponent> pRigidBody);
		~ControlComponent() = default;
		void Update(float) override {};

		void SetSpeed(int speed);
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
	private:
		int m_Speed;
		std::weak_ptr<RigidBodyComponent> m_pRigidBody;
	};	
}

