#pragma once

#include "resource.hpp"

const enum class GameState
{
	Play = 0,
	Pause,
	End
};

class Tetris3D
{
protected:
	sf::RenderWindow *Window;
	GameState State;
	inline void SetWindowIcon();
	inline void InitializeOpenGL();
	void ProcessEvents();
	void Resize(GLsizei x, GLsizei y);
	Field Field;
public:
	Tetris3D();
	~Tetris3D();
	void Run();
};
