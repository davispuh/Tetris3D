#pragma once

class BlockT : public Block
{
public:
	BlockT();
	~BlockT();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
