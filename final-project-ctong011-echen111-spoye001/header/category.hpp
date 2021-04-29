#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class Category : public Tag{
    private:
       string name;
        vector<Tag*> tags;
    public:
        Category(string name);
        virtual void addTag(Tag* tag);
        //virtual void removeTag(Tag* tag);
        virtual void display() const;
        virtual string getName() const;
        virtual Tag* find(string obj) const;
};

#endif
