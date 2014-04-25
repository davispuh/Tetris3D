#pragma once

class Field
{
protected:
	unsigned char FieldWidth = 10;
	unsigned char FieldLength = 10;
	unsigned char FieldHeight = 22;

	unsigned char StartWidth = 5;
	unsigned char StartLength = 5;
	unsigned char StartHeight = 22;

	struct Vertex {
		GLfloat vertex[3];
		GLfloat color[4];
	};

	static Buffers Buffers;
	static std::vector<Vertex> VertexData;
	static std::vector<GLubyte> Indices;
	std::vector<Block*> FieldBlocks;
	Block *ActiveBlock = nullptr;
	Block *AddBlock();

	Block *ActivateBlock();
	bool IsSectionFull(unsigned char row);
	bool AnySectionFull();

public:
	Field();
	~Field();
	void static Init();
	void static DeInit();
	void Start(unsigned char Width, unsigned char Length, unsigned char Height);
	void Destroy();
	bool HaveSpace();
	void HandleInput(sf::Time ElapsedTime);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
