#ifndef __RESTAURANT_HPP__
#define __RESTAURANT_HPP__

#include "item.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Restaurant {
	private:
		string name;
		double subtotal = 0;
		vector<Item *> order;
		vector<Item *> menu; 

	public:
		Restaurant(string name);
		void addItem(Item* );
		void removeItem(Item* );
		Item* getItem(int ) const;
		double getSubtotal() const;
		void display() const;
		string getRestaurantName() const;
		vector<Item *> getOrder() const;
		void createMenu();
		void printMenu();
		Item* getMenuItem(int ) const;
};
#endif // __RESTAURANT_HPP__
