/*#ifndef __TIMEBREAKDOWN_HPP__
#define __TIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
#include "restaurant.hpp"
using namespace std;

struct Time {
	string timeType;
	int time;
	Time(string timeType, int time) : timeType(timeType), time(time) {};
};

class TimeBreakdown{
    protected:
	vector<Time> timeBreakdown;
    public:
        TimeBreakdown();
        virtual void collectTimeMetaData(Restaurant *) = 0;
        vector<Time> getTimes() const {return timeBreakdown;}; 
};

#endif
*/
