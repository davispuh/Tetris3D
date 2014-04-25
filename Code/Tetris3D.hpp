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

struct MousePosition {
	int x;
	int y;
};

class Tetris3D
{
protected:
	sf::RenderWindow *Window;
	MousePosition PreviousMousePosition;
	Shader Shader;
	GameState State;
	inline void SetWindowIcon();
	inline void InitializeOpenGL();
	inline void DeInitializeOpenGL();
	void ProcessEvents();
	void Resize(GLsizei x, GLsizei y);
	Field Field;
public:
	Tetris3D();
	~Tetris3D();
	void Run();
};
