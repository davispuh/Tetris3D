#pragma once

class Field
{
protected:
	Block *FieldBlocks[100];
	unsigned int BlockCount = 0;
	Block *ActiveBlock = nullptr;
	Block *AddBlock();

	Block *ActivateBlock();
	bool IsSectionFull();

public:
	Field();
	~Field();
	void Start();
	void Destroy();
	bool HaveSpace();
	void Update();
	void Draw();
};
