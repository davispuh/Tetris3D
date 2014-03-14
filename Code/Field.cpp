#include "stdafx.hpp"

Field::Field()
{
}

Field::~Field()
{
	Destroy();
}

void Field::Start(unsigned char Width, unsigned char Length, unsigned char Height)
{
	FieldWidth = Width;
	FieldLength = Length;
	FieldHeight = Height;
}

void Field::Destroy()
{
	for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
	{
		delete *Block;
	}
	FieldBlocks.clear();
	ActiveBlock = nullptr;
}

bool Field::HaveSpace()
{
	// TODO
	return true;
}

Block *Field::AddBlock()
{
	auto Block = BlockChooser::GetBlock();
	Block->SetLocation(sf::Vector3i(FieldWidth / 2, FieldLength / 2, FieldHeight));
	FieldBlocks.push_back(Block);
	return Block;
}

Block *Field::ActivateBlock() {
	if (ActiveBlock == nullptr)
	{
		ActiveBlock = AddBlock();
	}
	return ActiveBlock;
}

void Field::HandleInput(sf::Time ElapsedTime) {
	ActiveBlock->HandleInput(ElapsedTime);
}

bool Field::IsSectionFull()
{
	// TODO
	return false;
}

void Field::Update(sf::Time ElapsedTime)
{
	if (IsSectionFull())
	{
		for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
		{
			(*Block)->Update(ElapsedTime);
		}
	}
	else
	{
		ActivateBlock();
		HandleInput(ElapsedTime);
	}
}

void Field::Draw()
{
	for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
	{
		(*Block)->Draw();
	}
}
