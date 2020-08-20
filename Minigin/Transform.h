#pragma once
namespace elfgine
{
	class Transform final
	{
	public:
		Transform();
		Transform(glm::vec2 position);
		Transform(glm::vec2 position, glm::vec2 scale);
		~Transform() = default;
		const glm::vec2& GetPosition() const;
		void SetPosition(float x, float y);
		void SetPosition(glm::vec2 newPos);
		void SetX(float x);
		void SetY(float x);
	private:
		 glm::vec2 m_Position;
		 glm::vec2 m_Scale;
	};
	
}