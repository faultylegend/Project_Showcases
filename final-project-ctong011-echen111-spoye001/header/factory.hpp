#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

/*#include API info*/
//#include "pricebreakdown.hpp"
//#include "uepricebreakdown.hpp"
//#include "ddpricebreakdown.hpp"
//#include "timebreakdown.hpp"
//#include "uetimebreakdown.hpp"
//#include "ddtimebreakdown.hpp"
#include "restaurant.hpp"

struct Fee {
	string feeType;
	double price;
	Fee(string feeType, double price) : feeType(feeType), price(price) {};
};

struct Time {
	string timeType;
	int time;
	Time(string timeType, int time) : timeType(timeType), time(time) {};
};

class Factory {
    protected:
        // PriceBreakdown* pbd;
        // TimeBreakdown* tbd;
        Restaurant* rest;
        vector<Fee> feeBreakdown;
        vector<Time> timeBreakdown;
    public:
        /* Pure Virtual Functions */
        Factory(Restaurant* rest) : rest(rest) {};
        virtual void createPriceBreakdown() = 0;
        virtual void createTimeBreakdown() = 0;
        vector<Fee> getFees() { return feeBreakdown; };
        vector<Time> getTimes() { return timeBreakdown; };
        // virtual void createRestaurantList() = 0;
};

class UberEatsFactory : public Factory{
    public:
        UberEatsFactory(Restaurant* rest);
        virtual void createPriceBreakdown();
        virtual void createTimeBreakdown();
        // virtual void createRestaurantList();
};

class DoorDashFactory : public Factory{
    public:
        DoorDashFactory(Restaurant* rest);
        virtual void createPriceBreakdown();
        virtual void createTimeBreakdown();
        // virtual void createRestaurantList();
};

#endif //__FACTORY_HPP__
