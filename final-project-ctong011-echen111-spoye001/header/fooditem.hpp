#ifndef __FOODITEM_HPP__
#define __FOODITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class FoodItem : public Tag{
    private:
       string name;
    public:
        FoodItem(string name);
        virtual void addTag(Tag* tag) {return;};
        //virtual void removeTag(Tag* tag) {return;};
        virtual void display() const;
        virtual string getName() const;
        virtual Tag* find(string obj) const;
};

#endif
