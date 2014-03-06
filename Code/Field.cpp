#include "stdafx.hpp"

Field::Field()
{
}

Field::~Field()
{
	Destroy();
}

void Field::Start()
{
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
	ActiveBlock->HandleInput();
	return ActiveBlock;
}

bool Field::IsSectionFull()
{
	// TODO
	return false;
}

void Field::Update()
{
	ActivateBlock();
	if (IsSectionFull())
	{
		for (unsigned int i = 0; i < BlockCount; i++)
		{
			FieldBlocks[i]->Update();
		}
	}
}

void Field::Draw()
{
	for (unsigned int i = 0; i < BlockCount; i++)
	{
		FieldBlocks[i]->Draw();
	}
}
