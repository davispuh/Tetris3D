#include "stdafx.hpp"

BaseBlock::BaseBlock(int x, int y, int z)
{
	Position.x = x;
	Position.y = y;
	Position.z = z;
}

sf::Vector3i BaseBlock::GetPosition()
{
	return Position;
}