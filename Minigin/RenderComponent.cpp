#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <string>
#include "Texture2D.h"

elfgine::RenderComponent::RenderComponent(std::shared_ptr<Transform> pTransform)
	: BaseComponent()
	, m_pTransform(pTransform)
	, m_pTexture(std::make_shared<Texture2D>(nullptr))
{
	
}

void elfgine::RenderComponent::ChangeTexture(std::shared_ptr<Texture2D> pTexture)
{
	m_pTexture = pTexture;
}

int elfgine::RenderComponent::GetTextureWidth() const
{
	return m_pTexture->GetWidth();
}

int elfgine::RenderComponent::GetTextureHeight() const
{
	return m_pTexture->GetHeight();
}

void elfgine::RenderComponent::Update(float)
{
	elfgine::Renderer::GetInstance().RenderTexture(*m_pTexture, m_pTransform.lock()->GetPosition().x, m_pTransform.lock()->GetPosition().y);
}

void elfgine::RenderComponent::SetTexture(const std::string& fileName, const std::string& keyName)
{
	auto& manager = ResourceManager::GetInstance();
	manager.AddTexture(fileName, keyName);
	m_pTexture = manager.GetTexture(keyName);
	
}