#ifndef FALLBLOCK_H
#define FALLBLOCK_H
#include "Block.h"

class FallBlock: public Block
{
private:
public:
	FallBlock();
	void Update();
	void Animate();
	~FallBlock();
};

#endif