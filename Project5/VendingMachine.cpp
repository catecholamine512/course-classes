#include "VendingMachine.h"


SnackSlot::SnackSlot(size_t capacity) {
	this->capacity = capacity;
	this->current_i = 0;
	this->snacks = new Snack * [capacity]();
}

SnackSlot::~SnackSlot() {
	delete[] this->snacks;
}

void SnackSlot::add_snack(Snack* snack) {
	if (current_i >= capacity) {
		std::cout << "attempt to overfill the SnackSlot!" << std::endl;
		return;
	}
	if (snack != nullptr) snacks[current_i++] = snack;
}

Snack* SnackSlot::pop_snack() {
	if (current_i == 0) {
		std::cout << "attempt to underflow the SnackSlot!" << std::endl;
		return nullptr;
	}
	--current_i;
	Snack* t = snacks[current_i];
	snacks[current_i] = nullptr;
	return t;
}

void SnackSlot::print_snacks() const {
	std::cout << "the current slot contents:" << std::endl;
	for (size_t i = 0; i < current_i; ++i) {
		if (snacks[i] != nullptr) std::cout << *snacks[i];
	}
}

size_t SnackSlot::get_snack_count() const {
	return current_i;
}


VendingMachine::VendingMachine(size_t slot_count) {
	this->slot_count = slot_count;
	this->current_i = 0;
	this->snack_slots = new SnackSlot * [slot_count]();
}

void VendingMachine::add_slot(SnackSlot* slot) {
	if (current_i >= slot_count) {
		std::cout << "attempt to overfill the VendingMachine!" << std::endl;
		return;
	}
	if (slot != nullptr) snack_slots[current_i++] = slot;
}

SnackSlot* VendingMachine::pop_slot() {
	if (current_i == 0) {
		std::cout << "attempt to underflow the SnackSlot!" << std::endl;
		return nullptr;
	}
	--current_i;
	SnackSlot* t = snack_slots[current_i];
	snack_slots[current_i] = nullptr;
	return t;
}

size_t VendingMachine::get_empty_slots_count() const {
	size_t count = 0;
	for (size_t i = 0; i < current_i; ++i) {
		if (snack_slots[i] == nullptr) continue;
		if (snack_slots[i]->get_snack_count() == 0) ++count;
	}
	return count;
}

size_t VendingMachine::get_total_snack_count() const {
	size_t count = 0;
	for (size_t i = 0; i < current_i; ++i) {
		if (snack_slots[i] == nullptr) continue;
		count += snack_slots[i]->get_snack_count();
	}
	return count;
}

Snack* VendingMachine::buy_snack(size_t slot_i) {
	if (slot_i >= current_i || snack_slots[slot_i] == nullptr) {
		std::cout << "attempt to buy from an uninitialized SnackSlot!" << std::endl;
		return nullptr;
	}
	if (snack_slots[slot_i]->get_snack_count() == 0) {
		std::cout << "attempt to buy from an empty SnackSlot!" << std::endl;
		return nullptr;
	}
	Snack* t = snack_slots[slot_i]->pop_snack();
	std::cout << "you are about to buy:" << std::endl;
	std::cout << *t;
	while (true) {
		std::cout << "confirm? (y/n): ";
		char c; std::cin >> c;
		if (c == 'y') {
			std::cout << "thanks for the purchase!" << std::endl;
			return t;
		}
		if (c == 'n') {
			std::cout << "aborting purchase!" << std::endl;
			snack_slots[slot_i]->add_snack(t);
			return nullptr;
		}
	}
}

VendingMachine::~VendingMachine() {
	delete[] this->snack_slots;
}

