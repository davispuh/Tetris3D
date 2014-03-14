#include "stdafx.hpp"


BlockS::BlockS()
{

}

Block *BlockS::Create()
{
	return new BlockS();
}

bool BlockS::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockS::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockS::Draw()
{
	// TODO
}
