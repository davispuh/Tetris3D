#pragma once

#define BlockJParts 4

class BlockJ : public Block
{
protected:
	BaseBlock *Parts[BlockJParts];
public:
	BlockJ();
	~BlockJ();
	static Block *Create();
	void Draw();
	void Update();
};
