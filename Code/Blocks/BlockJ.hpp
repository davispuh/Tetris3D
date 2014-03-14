#pragma once

class BlockJ : public Block
{
public:
	BlockJ();
	~BlockJ();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
