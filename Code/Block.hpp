#pragma once

class Block
{
protected:
	sf::Vector3f Position;

public:
	Block();
	static Block *Create();
	virtual void HandleInput(sf::Time ElapsedTime);
	virtual void Update(sf::Time ElapsedTime);
	virtual void Draw();
};
