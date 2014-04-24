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
	Position.x = ToPosition(Location.x);
	Position.y = ToPosition(Location.y);
	Position.z = ToPosition(Location.z);
}

glm::vec3 Block::ToLocation(glm::vec3 Position, float BaseSize)
{
	return glm::floor(Position / BaseSize);
}

int Block::ToLocation(float Position, float BaseSize)
{
	return (int)std::floor(Position / BaseSize);
}

float Block::ToPosition(int Location, float BaseSize)
{
	return Location * BaseSize;
}

glm::vec3 Block::ToLocation(glm::vec3 Position)
{
	return ToLocation(Position, BaseSize);
}

int Block::ToLocation(float Position)
{
	return ToLocation(Position, BaseSize);
}

float Block::ToPosition(int Location)
{
	return ToPosition(Location, BaseSize);
}

sf::Vector3i Block::GetLocation()
{
	glm::vec3 Location = Block::ToLocation(this->Position);
	return sf::Vector3i((int)Location.x, (int)Location.y, (int)Location.z);
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