#pragma once

class BlockZ : public Block
{
public:
	BlockZ();
	~BlockZ();
	static Block *Create();
	void Draw();
	void Update();
};
