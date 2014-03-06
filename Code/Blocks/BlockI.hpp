#pragma once

#define BlockIParts 4

class BlockI : public Block
{
protected:
	BaseBlock *Parts[BlockIParts];
public:
	BlockI();
	~BlockI();
	static Block *Create();
	void Draw();
	void Update();
};
