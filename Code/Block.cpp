#include "stdafx.hpp"

Block::Block()
{
	Position.x = 0.0;
	Position.y = 0.0;
	Position.z = 0.0;
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

void Block::HandleInput(sf::Time ElapsedTime)
{

}

void Block::Update(sf::Time ElapsedTime)
{

}


void Block::Draw()
{

}