#include "stdafx.hpp"


BlockZ::BlockZ()
{
	Parts.push_back(new BaseBlock(0, 1, 0));
	Parts.push_back(new BaseBlock(1, 1, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(2, 0, 0));
}

BlockZ::~BlockZ()
{
	DeleteParts();
}

Block *BlockZ::Create()
{
	return new BlockZ();
}
