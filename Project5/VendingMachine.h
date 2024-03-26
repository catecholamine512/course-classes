#pragma once
#include "Snack.h"


class SnackSlot
{
	size_t capacity;
	size_t current_i; // (partially) reinvent the stack
	Snack** snacks; // dynamic array of pointers
	// the invariant is supposed to be that current_i increments _only_ when a non-null snack is added

public:
	SnackSlot(size_t capacity);
	~SnackSlot();
	void add_snack(Snack* snack);
	Snack* pop_snack();
	void print_snacks() const;
	size_t get_snack_count() const;
};


class VendingMachine
{
	size_t slot_count;
	size_t current_i;
	SnackSlot** snack_slots; // same deal with **

public:
	VendingMachine(size_t slot_count);
	~VendingMachine();
	void add_slot(SnackSlot* slot);
	SnackSlot* pop_slot();
	size_t get_empty_slots_count() const;
	size_t get_total_snack_count() const;
	Snack* buy_snack(size_t slot_i);
};

