#pragma once
#include "GameObject.h"
#include "ControlComponent.h"
namespace elfgine
{
	class Projectile final : public GameObject
	{
	public:
		Projectile(const std::string& textureName, ControlComponent::moveDirection playerDirection, int speed);
		virtual ~Projectile() = default;
		Projectile(const Projectile& other) = delete;
		Projectile(Projectile&& other) = delete;
		Projectile& operator=(const Projectile& other) = delete;
		Projectile& operator=(Projectile&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		
	private:
		//Variables
		int m_ProjectileSpeed;
		ControlComponent::moveDirection m_ProjectileDir;
		std::weak_ptr<RigidBodyComponent> m_ThisRigidBody;
	};	
}

