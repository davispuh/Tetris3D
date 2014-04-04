#pragma once

class BlockJ : public Block
{
public:
	BlockJ();
	~BlockJ();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
