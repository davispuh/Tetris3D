#include "stdafx.hpp"

Block::Block()
{
	Position.x = 0.0;
	Position.y = 0.0;
	Position.z = 0.0;
}

Block::~Block()
{

}

void Block::DeleteParts()
{
	for (auto BlockPart = Parts.begin(); BlockPart != Parts.end(); ++BlockPart)
	{
		delete *BlockPart;
	};
}

void Block::SetLocation(sf::Vector3i Location)
{
	Position.x = Location.x * BaseSize;
	Position.y = Location.y * BaseSize;
	Position.z = Location.z * BaseSize;
}

sf::Vector3i Block::GetLocation()
{
	return sf::Vector3i(Position / BaseSize);
}

bool Block::AtLocation(int X, int Y, int Z)
{
	return false;
}

void Block::HandleInput(sf::Time ElapsedTime)
{

}

void Block::Update(sf::Time ElapsedTime)
{

}


void Block::Draw()
{

}