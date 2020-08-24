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

std::shared_ptr<elfgine::Texture2D> elfgine::RenderComponent::GetTexture() const
{
	return m_pTexture;
}

void elfgine::RenderComponent::Update(float)
{
	if(m_Enabled)
		elfgine::Renderer::GetInstance().RenderTexture(*m_pTexture, m_pTransform.lock()->GetPosition().x, m_pTransform.lock()->GetPosition().y);
}

void elfgine::RenderComponent::SetTexture(const std::string& keyName)
{
	auto& manager = ResourceManager::GetInstance();
	m_pTexture = manager.GetTexture(keyName);
	
}