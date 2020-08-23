#pragma once
#include "BaseComponent.h"
namespace elfgine
{
	class RigidBodyComponent;
	class ControlComponent :
		public BaseComponent
	{
	public:

		enum class moveDirection
		{
			Left,
			Right,
			Up,
			Down
		};
		
		ControlComponent(std::shared_ptr<RigidBodyComponent> pRigidBody);
		~ControlComponent() = default;
		void Update(float) override {};

		void SetIsOnGrid();
		bool GetIsOnGrid();
		void SetSpeed(int speed);
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		void Shoot();
	private:
		int m_Speed;
		std::weak_ptr<RigidBodyComponent> m_pRigidBody;
		moveDirection m_MoveDirection{};
		bool m_IsOnGrid{true};
		
	};	
}

