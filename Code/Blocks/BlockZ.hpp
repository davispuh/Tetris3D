#pragma once

class BlockZ : public Block
{
public:
	BlockZ();
	~BlockZ();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
