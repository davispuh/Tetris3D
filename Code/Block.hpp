#pragma once

class Block
{
protected:
	sf::Vector3f Position;

public:
	Block();
	static Block *Create();
	virtual void HandleInput();
	virtual void Update();
	virtual void Draw();
};
