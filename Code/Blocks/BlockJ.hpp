#pragma once

#define BlockJParts 4

class BlockJ : public Block
{
protected:
	BaseBlock *Parts[BlockJParts];
public:
	BlockJ();
	~BlockJ();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
