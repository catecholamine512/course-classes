#pragma once
#include "Snack.h"

class SnackSlot
{
	size_t capacity;
	Snack* snacks;
public:
	SnackSlot(size_t capacity);
	~SnackSlot();
};

