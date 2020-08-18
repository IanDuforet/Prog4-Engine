#pragma once
#include "BaseComponent.h"
#include "Transform.h"
namespace elfgine
{
	class Texture2D;
	class RenderComponent : public BaseComponent
	{
	public:
		RenderComponent(std::shared_ptr<Transform> pTransform);
		virtual ~RenderComponent() = default;
		void Update(float deltaTime) override;
		void SetTexture(const std::string& fileName, const std::string& keyName);
		void ChangeTexture(std::shared_ptr<Texture2D> pTexture);
		int GetTextureWidth() const;
		int GetTextureHeight() const;
		
	private:
		std::weak_ptr<Transform> m_pTransform;
		std::shared_ptr<Texture2D> m_pTexture{};
	};

}

