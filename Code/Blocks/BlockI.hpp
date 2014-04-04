#pragma once

class BlockI : public Block
{
public:
	BlockI();
	~BlockI();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
