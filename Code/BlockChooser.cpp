#include "stdafx.hpp"

namespace BlockChooser {

	std::vector<BlockFactory> BlockFactories;

	void InitBlockChooser()
	{
		BlockFactories.push_back(&BlockI::Create);
		BlockFactories.push_back(&BlockJ::Create);
		BlockFactories.push_back(&BlockL::Create);
		BlockFactories.push_back(&BlockO::Create);
		BlockFactories.push_back(&BlockS::Create);
		BlockFactories.push_back(&BlockT::Create);
		BlockFactories.push_back(&BlockZ::Create);
	}

	Block *GetBlock()
	{
		return BlockFactories[rand() % BlockFactories.size()]();
	}

};
