#include "stdafx.hpp"
#include "Tetris3D.hpp"

int main()
{
	BlockChooser::InitBlockChooser();
	Tetris3D tetris;
	tetris.Run();
	return EXIT_SUCCESS;
}
