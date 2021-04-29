/*#ifndef __PRICEBREAKDOWN_HPP__
#define __PRICEBREAKDOWN_HPP__

#include <iostream>
#include <vector>
#include "restaurant.hpp"
using namespace std;

struct Fee {
	string feeType;
	double price;
	Fee(string feeType, double price) : feeType(feeType), price(price) {};
};

class PriceBreakdown {
	protected:
		vector<Fee> feeBreakdown;
	public:
		PriceBreakdown();*/
		/*void sort() {
			for (unsigned int i = 0; i + 1 < feeBreakdown.size(); i++) {
				int min = i;
				for (unsigned int j = i + 1; j < feeBreakdown.size(); j++) {
					if (feeBreakdown.at(min)->feeType > feeBreakdown.at(j)->feeType) {
						min = j;
					}
				}
				Fee temp = feeBreakdown.at(min);
				feeBreakdown.at(min) = feeBreakdown.at(i);
				feeBreakdown.at(i) = temp;
			}
		};*/
		/*virtual void collectPriceMetadata(Restaurant *) = 0;
		vector<Fee> getFees() const {return feeBreakdown;}; 
};
#endif //__PRICEBREAKDOWN_HPP__
*/
//{(pickup, 10), (delivery, 20)}
//cookTime x num Items

// DeliveryOptionFactory* delfact = new UEDeliveryFactory();
// PriceBreakdown* pb = delfact->createPriceBreakdown()
// get each item they want price

// DD: DisneyBakery {beignet - 1, cookie - 2}
// UE: DisneyBakery {beignet - 2, cookie - 1}

// Restaurant r= DisneyBakery {beignet, cookie}
// -1 default
// r->addItem("beignet");
// r->addItem("cookie")

// choose Restaurant : DisneyBakery
// print menu
// add items to restaurant object as they choose with default price -1
// make factory after they choose if they want pricce or __TIME__
// make product which will automatically do the one that matches the factory
// get hte price information and fill in for item objects
// add tags if they want
// make strategy to compare the options

