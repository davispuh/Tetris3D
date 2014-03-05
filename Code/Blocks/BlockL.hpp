#pragma once

class BlockL : public Block
{
public:
	BlockL();
	~BlockL();
	static Block *Create();
	void Draw();
	void Update();
};
