#pragma once

class BlockO : public Block
{
public:
	BlockO();
	~BlockO();
	static Block *Create();
	void Draw();
	void Update();
};
