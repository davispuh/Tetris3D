#pragma once

class BaseBlock
{
protected:
	sf::Vector3i Position;

public:
	BaseBlock(int x, int y, int z);
	sf::Vector3i GetPosition();
};
