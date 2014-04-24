#include "stdafx.hpp"
#include "Tetris3D.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	BlockChooser::InitBlockChooser();
	Tetris3D tetris;
	tetris.Run();
	return EXIT_SUCCESS;
}
