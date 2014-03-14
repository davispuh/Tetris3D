#pragma once

class Field
{
protected:
	unsigned char FieldWidth = 10;
	unsigned char FieldLength = 10;
	unsigned char FieldHeight = 22;
	Block *FieldBlocks[100];
	unsigned int BlockCount = 0;
	Block *ActiveBlock = nullptr;
	Block *AddBlock();

	Block *ActivateBlock();
	bool IsSectionFull();

public:
	Field();
	~Field();
	void Start(unsigned char Width, unsigned char Length, unsigned char Height);
	void Destroy();
	bool HaveSpace();
	void HandleInput(sf::Time ElapsedTime);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
