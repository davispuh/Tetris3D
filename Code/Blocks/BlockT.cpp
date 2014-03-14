#include "stdafx.hpp"


BlockT::BlockT()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(1, 1, 0));
	Parts.push_back(new BaseBlock(2, 0, 0));
}

BlockT::~BlockT()
{
	DeleteParts();
}

Block *BlockT::Create()
{
	return new BlockT();
}

bool BlockT::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockT::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockT::Draw()
{
	// TODO
}
