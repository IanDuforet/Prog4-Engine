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
	int m_WindowHeight{ 600 };
	int m_WindowWidth{ 960 };
	int m_EmeraldValue{25};
	int m_GoldValue{ 500 };
};

