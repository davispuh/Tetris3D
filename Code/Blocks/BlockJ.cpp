#include "stdafx.hpp"


BlockJ::BlockJ()
{
	Parts.push_back(new BaseBlock(0, 0, 0));
	Parts.push_back(new BaseBlock(1, 0, 0));
	Parts.push_back(new BaseBlock(2, 0, 0));
	Parts.push_back(new BaseBlock(0, 1, 0));
}

BlockJ::~BlockJ()
{
	DeleteParts();
}

Block *BlockJ::Create()
{
	return new BlockJ();
}
