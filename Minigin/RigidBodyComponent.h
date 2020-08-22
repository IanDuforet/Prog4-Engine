#pragma once
#include "BaseComponent.h"

namespace elfgine
{
	
	
	class Transform;
	class RigidBodyComponent :
		public BaseComponent
	{
	public:
		RigidBodyComponent(std::shared_ptr<Transform> pTransform);
		virtual ~RigidBodyComponent() = default;
		void MoveLeft(float value);
		void MoveRight(float value);
		void MoveUp(float value);
		void MoveDown(float value);
		void Update(float deltaTime) override;
	private:
		glm::vec2 m_Velocity;
		std::weak_ptr<Transform> m_Transform;
		
	};
}

