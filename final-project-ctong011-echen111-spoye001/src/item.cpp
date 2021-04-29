#include "../header/item.hpp"
#include "../header/tag.hpp"
#include "../header/fooditem.hpp"
#include "../header/category.hpp"
#include <iostream>
using namespace std;

Item::Item(): name(""), price(-1), itemTag(nullptr) {}

void Item::displayItem() const{
    cout << this->name << " - $" << this->price << endl;
    if (itemTag != nullptr) { 
    	cout << "\tTags: ";
    	itemTag->display();
    	cout << endl;
    }
}

bool Item::operator==(const Item &otherItem) const{
    if (this->name == otherItem.name && this->price == otherItem.price){
        return true;
    }
    else{
        return false;
    }
}

void Item::setName(string name){
    this->name = name;
}

string Item::getName() const{
    return name;
}

void Item::setPrice(double price){
    this->price = price;
}

double Item::getPrice() const{
    return price;
}

void Item::addCategoryTag(string tag, string link){
    Tag* t = new Category(tag);
    if (link != ""){
        Tag* linker = itemTag->find(link);
        if (linker != nullptr){
            linker->addTag(t);
            //return;
        }
	else if (itemTag->getName() == link) {
	    itemTag->addTag(t);
	}
        else{
            delete t;
            //return;
        }
	return;
    } 
    else {
        if (itemTag != nullptr) {
		itemTag->addTag(t);
	} else {
		itemTag = t;
	}
    }
}

void Item::addFoodTag(string tag, string link){
    Tag* t = new FoodItem(tag);
    if (link != ""){
        Tag* linker = itemTag->find(link);
        if (linker != nullptr){
            linker->addTag(t);
            return;
        }
        else{
            delete t;
            return;
        }
    }
    
    else {
	if (itemTag != nullptr) {
            itemTag->addTag(t);
	}
	else {
	    itemTag = t;
	}
    }
}

// addTag(string tag, string link = "") [
        //     Tag* t = new Tag(tag);
        //     itemTag->addTag(t)
        //     if (link != "") {
        //         look for link
        //         add item under it
        //     }
        // ]
