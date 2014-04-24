#pragma once

class Block
{
protected:
	std::vector<BaseBlock*> Parts;
	sf::Vector3f Position;
	sf::Color Color;
	float BaseSize = 1.0f;
	void DeleteParts();

public:
	Block();
	virtual ~Block();
	static Block *Create();
	void SetLocation(sf::Vector3i Location);
	sf::Vector3i GetLocation();
	bool AtLocation(int X, int Y, int Z);
	void HandleInput(sf::Time ElapsedTime);
	void Update(sf::Time ElapsedTime);
	void Draw();
};
