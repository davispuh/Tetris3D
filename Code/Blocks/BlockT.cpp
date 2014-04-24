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
