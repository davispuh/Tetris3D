#pragma once

#include "resource.hpp"

const enum class UniformBindings
{
	Transformation = 0
};

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
	Shader Shader;
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
