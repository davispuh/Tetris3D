#include "stdafx.hpp"


BlockJ::BlockJ()
{
	Parts[0] = new BaseBlock(0, 0, 0);
	Parts[1] = new BaseBlock(1, 0, 0);
	Parts[2] = new BaseBlock(2, 0, 0);
	Parts[3] = new BaseBlock(0, 1, 0);
}

BlockJ::~BlockJ()
{
	for (int i = 0; i < BlockJParts; i++)
	{
		delete Parts[i];
	}
}

Block *BlockJ::Create()
{
	return new BlockJ();
}

bool BlockJ::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockJ::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockJ::Draw()
{
	// TODO
}
