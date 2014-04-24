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
	StartWidth = FieldWidth / 2;
	StartLength = FieldLength / 2;
	StartHeight = FieldHeight;
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
	if (ActiveBlock != nullptr && ActiveBlock->IsMoveable()) return true;
	for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
	{
		if ((*Block)->AtLocation(StartWidth, StartHeight, StartLength))
		{
			return false;
		}
	};
	return true;
}

Block *Field::AddBlock()
{
	auto Block = BlockChooser::GetBlock();
	Block->SetBlocks(&FieldBlocks);
	Block->SetBounds(FieldWidth, FieldLength);
	Block->SetLocation(sf::Vector3i(StartWidth, StartHeight, StartLength));
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

bool Field::IsSectionFull(unsigned char row)
{
	unsigned short count = 0;
	for (unsigned char z = 0; z < FieldLength; z++)
	{
		for (unsigned char x = 0; x < FieldWidth; x++) {
			for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
			{
				if ((*Block)->AtLocation(x, row, z)) count++;
			};
		};
	};
	return count >= FieldLength*FieldWidth;
}

bool Field::AnySectionFull()
{
	for (unsigned char row = 0; row < FieldHeight; row++)
	{
		if (IsSectionFull(row)) return true;
	};
	return false;
}

void Field::Update(sf::Time ElapsedTime)
{
	if (AnySectionFull())
	{
		for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
		{
			(*Block)->Update(ElapsedTime);
		}
	}
	else
	{
		ActivateBlock();
		ActiveBlock->Update(ElapsedTime);
		HandleInput(ElapsedTime);
	}
	if (!ActiveBlock->IsMoveable()) ActiveBlock = nullptr;
}

void Field::Draw()
{
	for (auto Block = FieldBlocks.begin(); Block != FieldBlocks.end(); ++Block)
	{
		(*Block)->Draw();
	}
}
