#pragma once

class BlockS : public Block
{
public:
	BlockS();
	~BlockS();
	static Block *Create();
	bool AtLocation(int X, int Y, int Z);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
