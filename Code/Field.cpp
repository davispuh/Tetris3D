#include "stdafx.hpp"

Buffers Field::Buffers = { 0, 0, 0 };

std::vector<Field::Vertex> Field::VertexData = {
	{
		{ 0.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 10.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 10.0f, 22.0f, 0.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 0.0f, 22.0f, 0.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 0.0f, 22.0f, 10.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 0.0f, 0.0f, 10.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 10.0f, 0.0f, 10.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}, {
		{ 10.0f, 22.0f, 10.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	}
};

std::vector<GLubyte> Field::Indices = {
	0, 1,
	1, 2,
	2, 3,
	3, 0,
	0, 5,
	5, 4,
	4, 3,
	1, 6,
	6, 7,
	7, 2,
	4, 7,
	5, 6
};

Field::Field()
{
}

Field::~Field()
{
	Destroy();
}

void Field::Init()
{
	glGenVertexArrays(1, &Buffers.VertexArrayObject);
	glBindVertexArray(Buffers.VertexArrayObject);
	glGenBuffers(3, &Buffers.VertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, Buffers.VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, VertexData.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer((GLuint)LayoutLocations::Vertex, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData[0]), (void*)offsetof(Vertex, vertex));
	glVertexAttribPointer((GLuint)LayoutLocations::Color, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData[0]), (void*)offsetof(Vertex, color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffers.IndexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(GLubyte), Indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray((GLuint)LayoutLocations::Vertex);
	glEnableVertexAttribArray((GLuint)LayoutLocations::Color);
}

void Field::DeInit()
{
	glDisableVertexAttribArray((GLuint)LayoutLocations::Vertex);
	glDisableVertexAttribArray((GLuint)LayoutLocations::Color);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(3, &Buffers.VertexBufferObject);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &Buffers.VertexArrayObject);
}

void Field::Start(unsigned char Width, unsigned char Length, unsigned char Height)
{
	FieldWidth = Width;
	FieldLength = Length;
	FieldHeight = Height;
	StartWidth = FieldWidth / 2;
	StartLength = FieldLength / 2;
	StartHeight = FieldHeight;

	for (auto Data = VertexData.begin(); Data != VertexData.end(); ++Data)
	{
		if (Data->vertex[0] != 0.0f)
		{
			Data->vertex[0] = FieldWidth;
		};
		if (Data->vertex[1] != 0.0f)
		{
			Data->vertex[1] = FieldHeight;
		};
		if (Data->vertex[2] != 0.0f)
		{
			Data->vertex[2] = FieldLength;
		};
	};
	glBindVertexArray(Buffers.VertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers.VertexBufferObject);
	glBufferSubData(GL_ARRAY_BUFFER, 0, VertexData.size() * sizeof(Vertex), VertexData.data());
	World::ModelMatrix().emplace(glm::translate(glm::mat4(1.0f), glm::vec3(-StartWidth, -FieldHeight / 2.0f, -StartLength)));
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
	glBindVertexArray(Buffers.VertexArrayObject);
	glDrawElements(GL_LINES, 12 * 2, GL_UNSIGNED_BYTE, nullptr);
}
