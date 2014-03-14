#pragma once

class BlockI : public Block
{
public:
	BlockI();
	~BlockI();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
