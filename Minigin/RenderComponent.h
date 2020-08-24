#pragma once
#include "BaseComponent.h"
#include "Transform.h"
namespace elfgine
{
	class Texture2D;
	class RenderComponent final : public BaseComponent
	{
	public:
		RenderComponent(std::shared_ptr<Transform> pTransform);
		virtual ~RenderComponent() = default;
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		void SetTexture(const std::string& keyName);
		void ChangeTexture(std::shared_ptr<Texture2D> pTexture);
		int GetTextureWidth() const;
		int GetTextureHeight() const;
		std::shared_ptr<Texture2D> GetTexture() const;
		
	private:
		//Variables
		std::weak_ptr<Transform> m_pTransform;
		std::shared_ptr<Texture2D> m_pTexture;
	};

}

