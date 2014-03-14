#include "stdafx.hpp"


BlockO::BlockO()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(1, 1, 0));
	Parts.push_back(new BaseBlock(0, 1, 0));
	Parts.push_back(new BaseBlock(0, 0, 1));
	Parts.push_back(new BaseBlock(1, 0, 1));
	Parts.push_back(new BaseBlock(1, 1, 1));
	Parts.push_back(new BaseBlock(0, 1, 1));
}

BlockO::~BlockO()
{
	DeleteParts();
}

Block *BlockO::Create()
{
	return new BlockO();
}

bool BlockO::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockO::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockO::Draw()
{
	// TODO
}
