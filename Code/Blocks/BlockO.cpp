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
