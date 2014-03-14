#include "stdafx.hpp"


BlockL::BlockL()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(2, 0, 0));
	Parts.push_back(new BaseBlock(2, 1, 0));
}

BlockL::~BlockL()
{
	DeleteParts();
}

Block *BlockL::Create()
{
	return new BlockL();
}

bool BlockL::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockL::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockL::Draw()
{
	// TODO
}
