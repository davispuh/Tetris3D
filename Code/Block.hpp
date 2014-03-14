#pragma once

class Block
{
protected:
	std::vector<BaseBlock*> Parts;
	sf::Vector3f Position;
	float BaseSize = 1.0f;
	void DeleteParts();
public:
	Block();
	virtual ~Block();
	static Block *Create();
	virtual void SetLocation(sf::Vector3i Location);
	virtual sf::Vector3i GetLocation();
	virtual bool AtLocation(int X, int Y, int Z);
	virtual void HandleInput(sf::Time ElapsedTime);
	virtual void Update(sf::Time ElapsedTime);
	virtual void Draw();
};
