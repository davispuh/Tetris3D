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

bool Block::IsMoveable() {
	return Moveable;
}

bool Block::MoveableTo(int X, int Y, int Z)
{
	for (auto BlockPart = Parts.begin(); BlockPart != Parts.end(); ++BlockPart)
	{
		sf::Vector3i PartPosition = (*BlockPart)->GetPosition();
		PartPosition.x += X;
		PartPosition.y += Y;
		PartPosition.z += Z;
		if (PartPosition.x < 0 || PartPosition.x >= Bounds.Width || PartPosition.y < 0 || PartPosition.z < 0 || PartPosition.z >= Bounds.Length)
		{
			return false;
		};
		for (auto Block = AllBlocks->begin(); Block != AllBlocks->end(); ++Block)
		{
			if ((*Block) == this) continue;
			if ((*Block)->AtLocation(PartPosition.x, PartPosition.y, PartPosition.z))
			{
				return false;
			};
		};
	};
	return true;
}

void Block::HandleInput(sf::Time ElapsedTime)
{
	if (!Moveable) return;
	float Speed = 5.0f;
	sf::Vector3i Location = GetLocation();
	bool Further = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Speed *= 10.0f;
		float nextY = Position.y - ElapsedTime.asSeconds() * Speed;
		int FinalLocation = ToLocation(nextY);
		for (int i = Location.y; i >= FinalLocation; i--)
		{
			Position.y = ToPosition(i);
			if (!MoveableTo(Location.x, i, Location.z))
			{
				Position.y += ToPosition(1);
				Moveable = false;
				break;
			};
		};
		if (Moveable)
		{
			Position.y += nextY - ToPosition(FinalLocation);
		};
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		float nextX = Position.x - ElapsedTime.asSeconds() * Speed;
		int FinalLocation = ToLocation(nextX);
		for (int i = Location.x; i >= FinalLocation; i--)
		{
			Position.x = ToPosition(i);
			if (!MoveableTo(i, Location.y, Location.z))
			{
				Position.x += ToPosition(1);
				Further = false;
				break;
			}
		}
		if (Further)
		{
			Position.x += nextX - ToPosition(FinalLocation);
		};
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		float nextX = Position.x + ElapsedTime.asSeconds() * Speed;
		int FinalLocation = ToLocation(nextX) + 1;
		for (int i = Location.x; i <= FinalLocation; i++)
		{
			Position.x = ToPosition(i);
			if (!MoveableTo(i, Location.y, Location.z))
			{
				Position.x -= ToPosition(1);
				Further = false;
				break;
			};
		};
		if (Further)
		{
			Position.x += nextX - ToPosition(FinalLocation);
		};
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float nextZ = Position.z - ElapsedTime.asSeconds() * Speed;
		int FinalLocation = ToLocation(nextZ);
		for (int i = Location.z; i >= FinalLocation; i--)
		{
			Position.z = ToPosition(i);
			if (!MoveableTo(Location.x, Location.y, i))
			{
				Position.z += ToPosition(1);
				Further = false;
				break;
			};
		};
		if (Further)
		{
			Position.z += nextZ - ToPosition(FinalLocation);
		};
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		float nextZ = Position.z + ElapsedTime.asSeconds() * Speed;
		int FinalLocation = ToLocation(nextZ) + 1;
		for (int i = Location.z; i <= FinalLocation; i++)
		{
			Position.z = ToPosition(i);
			if (!MoveableTo(Location.x, Location.y, i))
			{
				Position.z -= ToPosition(1);
				Further = false;
				break;
			};
		};
		if (Further)
		{
			Position.z += nextZ - ToPosition(FinalLocation);
		};
	};
}

void Block::Update(sf::Time ElapsedTime)
{
	if (!Moveable) return;
	float Speed = 2.0f;
	sf::Vector3i Location = GetLocation();
	float nextY = Position.y - ElapsedTime.asSeconds() * Speed;
	int FinalLocation = ToLocation(nextY);
	for (int i = Location.y; i >= FinalLocation; i--)
	{
		Position.y = ToPosition(i);
		if (!MoveableTo(Location.x, i, Location.z))
		{
			Position.y += ToPosition(1);
			Moveable = false;
			break;
		};
	};
	if (Moveable)
	{
		Position.y += nextY - ToPosition(FinalLocation);
	};
}

void Block::Draw()
{

}
