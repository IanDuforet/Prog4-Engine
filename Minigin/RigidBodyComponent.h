#pragma once
#include "BaseComponent.h"

namespace elfgine
{
	class RigidBodyComponent :
		public BaseComponent
	{
	public:
		RigidBodyComponent() = default;
		virtual ~RigidBodyComponent() = default;
		void MoveLeft(float value);
		void MoveRight(float value);
		void MoveUp(float value);
		void MoveDown(float value);
		void Update(float deltaTime) override;
	private:
		glm::vec2 m_Velocity;
	};
}

