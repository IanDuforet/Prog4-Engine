#pragma once
#include "GameObject.h"
#include "ControlComponent.h"
namespace elfgine
{
	class Projectile :
		public GameObject
	{
	public:

		Projectile(const std::string& textureName, ControlComponent::moveDirection playerDirection, int speed);
		void Update(float deltaTime) override;
		virtual ~Projectile() = default;
	private:
		ControlComponent::moveDirection m_ProjectileDir;
		std::weak_ptr<RigidBodyComponent> m_ThisRigidBody;
		int m_ProjectileSpeed;
	};	
}

