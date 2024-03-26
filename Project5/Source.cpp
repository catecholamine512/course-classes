#include <iostream>
#include <string>
#include "Snack.h"
#include "VendingMachine.h"


int main(void) {
	Snack* bounty = new Snack("Bounty", 5, 200);
	Snack* snickers = new Snack("Snickers", 4, 180);
	Snack* test_snack = new Snack();

	SnackSlot* slot0 = new SnackSlot(10);
	slot0->add_snack(bounty);
	slot0->add_snack(snickers);
	slot0->add_snack(test_snack);

	slot0->print_snacks();

	Snack* test2 = slot0->pop_snack();

	slot0->print_snacks();

	VendingMachine* vending_machine = new VendingMachine(5);
	vending_machine->add_slot(slot0);

	SnackSlot* slot1 = new SnackSlot(10);
	slot1->add_snack(snickers);
	slot1->add_snack(snickers);
	slot1->add_snack(bounty);
	slot1->add_snack(bounty);
	vending_machine->add_slot(slot1);

	SnackSlot* slot2 = new SnackSlot(10);
	vending_machine->add_slot(slot2);

	std::cout << vending_machine->get_empty_slots_count() << std::endl;
	std::cout << vending_machine->get_total_snack_count() << std::endl;

	Snack* bought = vending_machine->buy_snack(1);

	delete bounty;
	delete snickers;
	delete test_snack;
	delete slot0;
	delete slot1;
	return 0;
}
