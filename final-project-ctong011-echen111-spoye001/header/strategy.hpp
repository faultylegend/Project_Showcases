#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <string>
#include <iostream>
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
#include "factory.hpp"
using namespace std;

class Restaurant;

class Strategy {
    protected:
        Restaurant* rest;
        Factory* uefact = new UberEatsFactory(rest);
        Factory* ddfact = new DoorDashFactory(rest);

    public:
        /* Constructors */
        Strategy(Restaurant* rest) : rest(rest) { };

        /* Pure Virtual Functions */
        virtual void compare() = 0;
        // virtual void print() = 0;
};

#endif //__STRATEGY_HPP__

// client:
// DeliveryOptionFactory* ue = new UberEatsEdlivery;

// DeliveryOptionFactory* dd = new DoorDashDelivery;
// ue->pricebreakdown();
// dd->pricebreakdown();
// info = ue->extractinfo
// Strategy* s = new PriceStrategy();
// s->compare(info1, info2);
