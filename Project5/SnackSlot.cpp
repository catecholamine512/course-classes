#include "SnackSlot.h"

SnackSlot::SnackSlot(size_t capacity = 10) {
	this->capacity = capacity;
	// this->snacks = new Snack[capacity]();
}

SnackSlot::~SnackSlot() {
	delete[] this->snacks;
}