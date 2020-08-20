#pragma once
namespace elfgine
{
	class SceneObject
	{

		
	public:
		virtual void Update(float deltaTime) = 0;
		virtual void FixedUpdate() = 0;
		void SetDelete()
		{
			m_Delete = true;
		};
		bool CheckDelete()
		{
			return m_Delete;
		};
		
		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;
	private:
		bool m_Delete{false};
		
	};

}
