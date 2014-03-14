#include "stdafx.hpp"


BlockO::BlockO()
{

}

Block *BlockO::Create()
{
	return new BlockO();
}

bool BlockO::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockO::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockO::Draw()
{
	// TODO
}
