#pragma once
#include <string>
#include <iostream>


class Snack
{
	std::string name;
	double price;
	double calories;

public:
	Snack();
	Snack(std::string name, double price, double calories);
	std::string get_name() const;
	double get_price() const;
	double get_calories() const;
	void set_name(std::string name);
	void set_price(double price);
	void set_calories(double calories);
	friend std::ostream& operator<<(std::ostream &output, const Snack &s);
};

