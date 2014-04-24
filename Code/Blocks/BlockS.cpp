#include "stdafx.hpp"


BlockS::BlockS()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(1, 1, 0));
	Parts.push_back(new BaseBlock(2, 1, 0));
}

BlockS::~BlockS()
{
	DeleteParts();
}

Block *BlockS::Create()
{
	return new BlockS();
}
