#include "stdafx.hpp"

Block::Block()
{
	Position.x = 0.0f;
	Position.y = 0.0f;
	Position.z = 0.0f;
	Color.r = (rand() % 21 + 3) * 10;
	Color.g = (rand() % 21 + 3) * 10;
	Color.b = (rand() % 21 + 3) * 10;
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

void Block::SetBlocks(std::vector<Block*> *AllBlocks)
{
	this->AllBlocks = AllBlocks;
}

void Block::SetBounds(int Width, int Length)
{
	Bounds.Width = (float)Width;
	Bounds.Length = (float)Length;
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
	sf::Vector3i Location = GetLocation();
	for (auto BlockPart = Parts.begin(); BlockPart != Parts.end(); ++BlockPart)
	{
		if ((*BlockPart)->AtLocation(X - Location.x, Y - Location.y, Z - Location.z))
		{
			return true;
		};
	};
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