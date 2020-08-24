#pragma once
#include "BaseComponent.h"
namespace elfgine
{
	class Transform;
	class TransformComponent final : public BaseComponent
	{
	public:
		TransformComponent(std::shared_ptr<Transform> pTransform);
		virtual ~TransformComponent() = default;
		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		std::shared_ptr<Transform> GetTransform() const;
		void SetPosition(float x, float y);
		void SetPosition(glm::vec2 pos);
	protected:
		//Variables
		std::shared_ptr<Transform> m_pTransform;
	};
}

