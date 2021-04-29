#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <string>
#include "strategy.hpp"
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
using namespace std;

class Restaurant;

class TimeStrategy : public Strategy {
    public:
        /*Constructors*/
        TimeStrategy(Restaurant* rest);

        /*Pure Virtual Functions*/
        virtual void compare();
        //virtual void print();
};

#endif //__TIME_HPP__S