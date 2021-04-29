#ifndef __UEPRICEBREAKDOWN_HPP__
#define __UEPRICEBREAKDOWN_HPP__

#include <iostream>
#include <vector>
#include "pricebreakdown.hpp"

class UEPriceBreakdown : public PriceBreakdown {
	public:
		UEPriceBreakdown();
		virtual void collectPriceMetadata(Restaurant *);
};
#endif //__UEPRICEBREAKDOWN_HPP__
