#ifndef __ITEM_HPP__
#define __ITEM_HPP__
#include <vector>
#include <iostream>
#include <string>
#include "tag.hpp"
#include "category.hpp"
#include "fooditem.hpp"
using namespace std;

class Item{
    private:
        Tag* itemTag;
        string name;
        double price;
    public:
        Item();
        Item(string name, double price): name(name), price(price), itemTag(nullptr){};
        void setName(string name);
        string getName() const;
        void setPrice(double price);
        double getPrice() const;
        void displayItem() const;
        bool operator==(const Item &otherItem) const;
        void addCategoryTag(string tag, string link = "");
        void addFoodTag(string tag, string link = "");
        // addTag(string tag, string link = "") [
        //     Tag* t = new Tag(tag);
        //     itemTag->addTag(t)
        //     if (link != "") {
        //         look for link
        //         add item under it
        //     }
        // ]
};

#endif
