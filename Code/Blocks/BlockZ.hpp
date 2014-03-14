#pragma once

class BlockZ : public Block
{
public:
	BlockZ();
	~BlockZ();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
