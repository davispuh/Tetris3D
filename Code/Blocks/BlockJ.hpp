#pragma once

class BlockJ : public Block
{
public:
	BlockJ();
	~BlockJ();
	static Block *Create();
	void Draw();
	void Update();
};
