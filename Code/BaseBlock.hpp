#pragma once

const enum class LayoutLocations
{
	Vertex = 0,
	Normal,
	TextureCoord,
	Color
};

struct Color {
	GLfloat Red;
	GLfloat Green;
	GLfloat Blue;
	GLfloat Alpha;
};

struct Buffers {
	GLuint VertexArrayObject;
	GLuint VertexBufferObject;
	GLuint IndexBufferObject;
	GLuint ColorBuffer;
};

class BaseBlock
{
protected:
	struct Vertex {
		GLfloat vertex[3];
		GLfloat normal[3];
		GLfloat texCoord[2];
	};
	static Buffers Buffers;
	static std::vector<Vertex> VertexData;
	static std::vector<Color> VertexColors;
	static std::vector<GLubyte> Indices;

	sf::Vector3i Position;

public:
	void static Init();
	void static SetColor(float Red, float Green, float Blue, float Alpha);
	void static Draw();
	void static DeInit();
	BaseBlock(int x, int y, int z);
	sf::Vector3i GetPosition();
	bool AtLocation(int X, int Y, int Z);
};
