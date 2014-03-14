#pragma once

namespace BlockChooser {

	typedef Block *(*BlockFactory)();
	void InitBlockChooser();
	Block *GetBlock();

};
