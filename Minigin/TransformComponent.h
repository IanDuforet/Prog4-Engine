#pragma once
#include "BaseComponent.h"
namespace elfgine
{
	class Transform;
	class TransformComponent :
		public BaseComponent
	{
	public:
		TransformComponent(std::shared_ptr<Transform> pTransform);
		std::shared_ptr<Transform> GetTransform() const;
		void SetPosition(float x, float y);
		void SetPosition(glm::vec2 pos);
	protected:
		std::shared_ptr<Transform> m_pTransform;
		void Update(float deltaTime);
	};
}

