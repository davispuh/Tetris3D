#pragma once

class BlockL : public Block
{
public:
	BlockL();
	~BlockL();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
