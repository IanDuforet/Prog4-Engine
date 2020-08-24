#pragma once
#include "BaseComponent.h"

namespace elfgine
{
	class Transform;
	class RigidBodyComponent final : public BaseComponent
	{
	public:
		RigidBodyComponent(std::shared_ptr<Transform> pTransform);
		virtual ~RigidBodyComponent() = default;
		RigidBodyComponent(const RigidBodyComponent& other) = delete;
		RigidBodyComponent(RigidBodyComponent&& other) = delete;
		RigidBodyComponent& operator=(const RigidBodyComponent& other) = delete;
		RigidBodyComponent& operator=(RigidBodyComponent&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		
		//Interactions
		void MoveLeft(float value);
		void MoveRight(float value);
		void MoveUp(float value);
		void MoveDown(float value);
		
	private:
		//Variables
		glm::vec2 m_Velocity;
		std::weak_ptr<Transform> m_Transform;
		
	};
}

