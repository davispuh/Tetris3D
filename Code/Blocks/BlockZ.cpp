#include "stdafx.hpp"


BlockZ::BlockZ()
{

}

Block *BlockZ::Create()
{
	return new BlockZ();
}

bool BlockZ::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockZ::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockZ::Draw()
{
	// TODO
}
