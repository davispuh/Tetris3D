#pragma once

class BlockL : public Block
{
public:
	BlockL();
	~BlockL();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
