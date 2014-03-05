#include "stdafx.hpp"

namespace BlockChooser {

	BlockFactory BlockFactories[MAX_BLOCK_COUNT];
	unsigned int FactoryCount = 0;

	void InitBlockChooser()
	{
		BlockFactories[FactoryCount++] = &BlockI::Create;
		BlockFactories[FactoryCount++] = &BlockJ::Create;
		BlockFactories[FactoryCount++] = &BlockL::Create;
		BlockFactories[FactoryCount++] = &BlockO::Create;
		BlockFactories[FactoryCount++] = &BlockS::Create;
		BlockFactories[FactoryCount++] = &BlockT::Create;
		BlockFactories[FactoryCount++] = &BlockZ::Create;
	}

	Block *GetBlock()
	{
		return BlockFactories[rand() % FactoryCount]();
	}

};
