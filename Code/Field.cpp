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
	for (unsigned int i = 0; i < BlockCount; i++)
	{
		delete FieldBlocks[i];
	}
	BlockCount = 0;
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
	FieldBlocks[BlockCount++] = Block;
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
		for (unsigned int i = 0; i < BlockCount; i++)
		{
			FieldBlocks[i]->Update(ElapsedTime);
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
	for (unsigned int i = 0; i < BlockCount; i++)
	{
		FieldBlocks[i]->Draw();
	}
}
