#ifndef __TAG_HPP__
#define __TAG_HPP__
#include <vector>
#include <iostream>
using namespace std;

class Tag{
    private:

    public:
        virtual void addTag(Tag* tag) = 0;
        //virtual void removeTag(Tag* tag) = 0;
        virtual void display() const = 0;
        virtual string getName() const = 0;
        virtual Tag* find(string obj) const = 0;
};

#endif