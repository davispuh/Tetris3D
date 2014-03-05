#pragma once

#define MAX_BLOCK_COUNT 10

namespace BlockChooser {

	typedef Block *(*BlockFactory)();
	void InitBlockChooser();
	Block *GetBlock();

};
