#ifndef __DDTIMEBREAKDOWN_HPP__
#define __DDTIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
#include "timebreakdown.hpp"
using namespace std;

class DDTimeBreakdown: public TimeBreakdown{
    private:

    public:
        DDTimeBreakdown();
        void collectTimeMetaData(Restaurant *);
};

#endif
