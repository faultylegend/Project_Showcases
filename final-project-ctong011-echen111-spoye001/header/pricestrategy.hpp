#ifndef __PRICE_HPP__
#define __PRICE_HPP__

#include <string>
#include "strategy.hpp"
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
using namespace std;

class Restaurant;

class PriceStrategy : public Strategy {
    public:
        /*Constructors*/
        PriceStrategy(Restaurant* rest);

        /*Pure Virtual Functions*/
        virtual void compare();
        // virtual void print();
};

#endif //__PRICE_HPP__