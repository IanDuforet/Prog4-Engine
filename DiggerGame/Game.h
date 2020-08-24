#pragma once
class Game
{
public:
	void Run();
private:
	
	void LoadTextures();

	//Scene stuff
	void LoadScenes();
	void LoadScene1();
	void LoadScene2();
	void LoadScene3();
	
	//Variables
	const int m_WindowHeight{ 600 };
	const int m_WindowWidth{ 960 };
	const int m_EmeraldValue{25};
	const int m_GoldValue{ 500 };
	const int m_NobbinValue{250};
	const int m_HobbinValue{250};
	const int m_PlayerSpeed{200};
	const float m_ShootCoolDown{2.f};
};

