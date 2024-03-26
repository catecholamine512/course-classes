#include "Snack.h"


Snack::Snack() {
	this->name = "Test snack";
	this->price = 1;
	this->calories = 100;
}

Snack::Snack(std::string name, double price, double calories) {
	this->set_name(name);
	this->set_price(price);
	this->set_calories(calories);
}

std::string Snack::get_name() const {
	return this->name;
}

double Snack::get_price() const {
	return this->price;
}

double Snack::get_calories() const {
	return this->calories;
}

void Snack::set_name(std::string name) {
	if (name.empty()) name = "TESTING";
	this->name = name;
}

void Snack::set_price(double price) {
	if (price <= 0) price = 100;
	this->price = price;
}

void Snack::set_calories(double calories) {
	if (calories <= 0) calories = 1000;
	this->calories = calories;
}

std::ostream& operator<<(std::ostream& output, const Snack& s) {
	output << "snack name: " << s.name << std::endl;
	output << "snack price: " << s.price << std::endl;
	output << "snack calories: " << s.calories << std::endl << std::endl;
	return output;
}

