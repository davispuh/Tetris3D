#pragma once

class BlockI : public Block
{
public:
	BlockI();
	~BlockI();
	static Block *Create();
	void Draw();
	void Update();
};
