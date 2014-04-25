#include "stdafx.hpp"

Buffers BaseBlock::Buffers = { 0, 0, 0 };

std::vector<BaseBlock::Vertex> BaseBlock::VertexData = {
	{
		{ 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 0.0f, 1.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 1.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}, {
		{ 1.0f, 1.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f }
	}
};

std::vector<Color> BaseBlock::VertexColors = {
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f }
};

std::vector<GLubyte> BaseBlock::Indices = {
	0, 1, 2, 3,
	4, 1, 5,
	0, 6,
	2, 7,
	4,
	6, 5
};

void BaseBlock::Init()
{
	glGenVertexArrays(1, &Buffers.VertexArrayObject);
	glBindVertexArray(Buffers.VertexArrayObject);
	glGenBuffers(3, &Buffers.VertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, Buffers.VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, VertexData.size() * sizeof(Vertex), VertexData.data(), GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)LayoutLocations::Vertex, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData[0]), (void*)offsetof(Vertex, vertex));
	glVertexAttribPointer((GLuint)LayoutLocations::Normal, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData[0]), (void*)offsetof(Vertex, normal));
	glVertexAttribPointer((GLuint)LayoutLocations::TextureCoord, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData[0]), (void*)offsetof(Vertex, texCoord));

	glBindBuffer(GL_ARRAY_BUFFER, Buffers.ColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, VertexColors.size() * sizeof(Color), VertexColors.data(), GL_DYNAMIC_DRAW);
	glVertexAttribPointer((GLuint)LayoutLocations::Color, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffers.IndexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(GLubyte), Indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray((GLuint)LayoutLocations::Vertex);
	glEnableVertexAttribArray((GLuint)LayoutLocations::Normal);
	glEnableVertexAttribArray((GLuint)LayoutLocations::TextureCoord);
	glEnableVertexAttribArray((GLuint)LayoutLocations::Color);
}

void BaseBlock::DeInit()
{
	glDisableVertexAttribArray((GLuint)LayoutLocations::Vertex);
	glDisableVertexAttribArray((GLuint)LayoutLocations::Normal);
	glDisableVertexAttribArray((GLuint)LayoutLocations::TextureCoord);
	glDisableVertexAttribArray((GLuint)LayoutLocations::Color);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(3, &Buffers.VertexBufferObject);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &Buffers.VertexArrayObject);
}

BaseBlock::BaseBlock(int x, int y, int z)
{
	Position.x = x;
	Position.y = y;
	Position.z = z;
}

sf::Vector3i BaseBlock::GetPosition()
{
	return Position;
}

bool BaseBlock::AtLocation(int X, int Y, int Z)
{
	return Position.x == X && Position.y == Y && Position.z == Z;
}

void BaseBlock::SetColor(float Red, float Green, float Blue, float Alpha)
{
	for (auto VertexColor = VertexColors.begin(); VertexColor != VertexColors.end(); ++VertexColor)
	{
		VertexColor->Red = Red;
		VertexColor->Green = Green;
		VertexColor->Blue = Blue;
		VertexColor->Alpha = Alpha;
	};
	glBindVertexArray(Buffers.VertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers.ColorBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, VertexColors.size() * sizeof(Color), VertexColors.data());
}

void BaseBlock::Draw()
{
	glBindVertexArray(Buffers.VertexArrayObject);
	glDrawElements(GL_TRIANGLE_STRIP, 4 + 3 + 2 + 2 + 1 + 2, GL_UNSIGNED_BYTE, nullptr);
}
