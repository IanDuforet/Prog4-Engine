#pragma once
#include "BaseComponent.h"
namespace elfgine
{
	class RigidBodyComponent;
	class ControlComponent final : public BaseComponent
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
		virtual ~ControlComponent() = default;
		ControlComponent(const ControlComponent& other) = delete;
		ControlComponent(ControlComponent&& other) = delete;
		ControlComponent& operator=(const ControlComponent& other) = delete;
		ControlComponent& operator=(ControlComponent&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		void SetIsOnGrid();
		bool GetIsOnGrid() const;
		void SetSpeed(int speed);
		void SetShootCooldown(float coolDown);

		//Interactions
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		void Shoot();
		
	private:
		//Variables
		int m_Speed;
		bool m_IsOnGrid;
		float m_CoolDownCounter;
		float m_CoolDown;
		std::weak_ptr<RigidBodyComponent> m_pRigidBody;
		moveDirection m_MoveDirection;
	};	
}

