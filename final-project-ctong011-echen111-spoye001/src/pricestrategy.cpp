#include "../header/pricestrategy.hpp"
#include "../header/pricebreakdown.hpp"
using namespace std;

PriceStrategy::PriceStrategy(Restaurant* rest) : Strategy(rest) {}

void PriceStrategy::compare(){
    uefact->createPriceBreakdown();
    ddfact->createPriceBreakdown();
    // uepbd->collectPriceMetadata(rest);
    // ddpbd->collectPriceMetadata(rest);
    vector<Fee> uefees = uefact->getFees();
    vector<Fee> ddfees = ddfact->getFees();
    rest->display();
    // cout << "Restaurant: " << rest->getRestaurantName() << endl;
    // cout << "Order: " << endl;
    // double orderSum = 0;
    // for (auto i : rest->getOrder()) {
    //     cout << i->getName() << " - $" << i->getPrice() << endl; 
    //     orderSum += i->getPrice();
    // }
    // cout << endl;
    // cout << "Cost - $" << orderSum << endl << endl;
    double orderSum = rest->getSubtotal();
    cout << "UberEats: " << endl;
    double feeSum = 0;
    for (auto i : uefees) {
        cout << i.feeType << " - $" << i.price << endl;
        feeSum += i.price;
    }
    cout << endl;
    cout << "Total Cost - $" << orderSum + feeSum << endl;
    cout << endl;
    
    cout << "DoorDash: " << endl;
    feeSum = 0;
    for (auto i : ddfees) {
        cout << i.feeType << " - $" << i.price << endl;
        feeSum += i.price;
    }
    cout << endl;
    cout << "Total Cost - $" << orderSum + feeSum << endl;
    cout << endl;

    // string uberPrice = restaurant->priceBreakdown(uber);
    // string dashPrice = restaurant->priceBreakdown(dash); 
}

// void PriceStrategy::print(){
//     cout << "UberEats Price: " << uberPrice;
//     cout << "DoorDash Price: " << dashPrice;
// }

// Restaurant: DisneyBakery
// Order:
// Waffle - $2.00
// Cookie - $1.00

// Cost - $3.00

// UberEats:
// Handling - $1.50
// Delivery - $5.00
// Tax - $3.00
// Small Order Fee - $1.00
// Total Cost - $13.50

// DoorDash:
// Handling - $1.00
// Delivery - $7.00
// Tax - $3.00
// Total Cost - $14.00