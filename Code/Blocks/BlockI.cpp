#include "stdafx.hpp"

BlockI::BlockI()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(2, 0, 0));
	Parts.push_back(new BaseBlock(3, 0, 0));
}

BlockI::~BlockI()
{
	DeleteParts();
}

Block *BlockI::Create()
{
	return new BlockI();
}

void BlockI::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockI::Draw()
{
	// TODO
}
