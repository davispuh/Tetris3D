#pragma once

class BlockO : public Block
{
public:
	BlockO();
	~BlockO();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
