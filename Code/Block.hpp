#pragma once

class Block
{
protected:
	sf::Vector3f Position;

public:
	Block();
	static Block *Create();
	virtual void Draw();
	virtual void Update();
};
