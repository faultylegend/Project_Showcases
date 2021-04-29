#include "../header/fooditem.hpp"

FoodItem::FoodItem(string name) : name(name) {}

void FoodItem::display() const {
    cout << name;
}

string FoodItem::getName() const{
    return name;
}

Tag* FoodItem::find(string obj) const{
    return nullptr;
}
