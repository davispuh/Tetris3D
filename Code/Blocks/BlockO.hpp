#pragma once

class BlockO : public Block
{
public:
	BlockO();
	~BlockO();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
