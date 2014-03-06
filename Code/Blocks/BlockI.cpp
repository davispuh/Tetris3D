#include "stdafx.hpp"

BlockI::BlockI()
{
	Parts[0] = new BaseBlock(0, 0, 0);
	Parts[1] = new BaseBlock(1, 0, 0);
	Parts[2] = new BaseBlock(2, 0, 0);
	Parts[3] = new BaseBlock(3, 0, 0);
}

BlockI::~BlockI()
{
	for (int i = 0; i < BlockIParts; i++)
	{
		delete Parts[i];
	}
}

Block *BlockI::Create()
{
	return new BlockI();
}


void BlockI::Draw()
{
	// TODO
}

void BlockI::Update()
{
	// TODO
}

