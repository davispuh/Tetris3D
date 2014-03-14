#include "stdafx.hpp"


BlockT::BlockT()
{

}

Block *BlockT::Create()
{
	return new BlockT();
}

bool BlockT::AtLocation(int X, int Y, int Z)
{
	// TODO
	return false;
}

void BlockT::Update(sf::Time ElapsedTime)
{
	// TODO
}

void BlockT::Draw()
{
	// TODO
}
