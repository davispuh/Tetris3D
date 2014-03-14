#pragma once

class BlockT : public Block
{
public:
	BlockT();
	~BlockT();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
