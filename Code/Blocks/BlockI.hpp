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
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
