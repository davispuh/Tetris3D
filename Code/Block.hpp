#pragma once

class Block
{
protected:
	std::vector<Block*> *AllBlocks;
	std::vector<BaseBlock*> Parts;
	sf::Vector3f Position;
	struct {
		float Width;
		float Length;
	} Bounds;
	sf::Color Color;
	float BaseSize = 1.0f;
	void DeleteParts();

public:
	Block();
	virtual ~Block();
	static Block *Create();
	static inline glm::vec3 ToLocation(glm::vec3 Position, float BaseSize);
	static int inline ToLocation(float Position, float BaseSize);
	static float inline ToPosition(int Location, float BaseSize);
	inline glm::vec3 ToLocation(glm::vec3 Position);
	int inline ToLocation(float Position);
	float inline ToPosition(int Location);
	void SetBlocks(std::vector<Block*> *AllBlocks);
	void SetBounds(int Width, int Length);
	void SetLocation(sf::Vector3i Location);
	sf::Vector3i GetLocation();
	bool AtLocation(int X, int Y, int Z);
	void HandleInput(sf::Time ElapsedTime);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
