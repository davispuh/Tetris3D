#include "stdafx.hpp"


BlockL::BlockL()
{

}

Block *BlockL::Create()
{
	return new BlockL();
}

bool BlockL::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockL::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockL::Draw()
{
	// TODO
}
