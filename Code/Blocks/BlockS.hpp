#pragma once

class BlockS : public Block
{
public:
	BlockS();
	~BlockS();
	static Block *Create();
	void Update(sf::Time ElapsedTime);
	void Draw();
};
