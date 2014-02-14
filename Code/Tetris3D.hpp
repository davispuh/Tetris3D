#pragma once

#include "resource.hpp"

class Tetris3D
{
protected:
	sf::RenderWindow *Window;
	inline void SetWindowIcon();
	inline void InitializeOpenGL();
public:
	Tetris3D();
	~Tetris3D();
	void Run();
};
