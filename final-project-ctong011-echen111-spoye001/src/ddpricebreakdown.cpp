#include "../header/pricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

DDPriceBreakdown::DDPriceBreakdown() {}

void DDPriceBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/DoorDash - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> column; 
    string line, word, temp;
    getline(fin, line);
    istringstream ss(line);
    int colIdx = 0;
    while(ss >> word){
        if(word == rest->getRestaurantName()){
            column.push_back(word);
            break;
        }
        else{
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }
    }
    while(getline(fin,line)){
        int columnIdx = 0;
        while(ss >> word){
            if(columnIdx == colIdx){
                column.push_back(word);
                if(ss.peek() == ',') ss.ignore();
            }
            else{
                columnIdx++;
            }
        }
    }


    fin.close();

    double subtotal = rest->getSubtotal();
    //small order fee
    double smallFee = 2.50;
    //if subtotal(before tax + promocode) < 15, apply small order fee
    if(subtotal < 10){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(small);
    }
    //promocode calculations: 20% off on orders > $15, up to $5
    if(subtotal > 15 && subtotal < 25){
        subtotal = .80 * subtotal;
    } 
    //tax = 8.72% x cost
    double tFee = 0.0872*subtotal;
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //service fee = servicefee% x subtotal
    double servFee = subtotal * stod(column[4]);
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery fee = fee x distance
    double dFee = stod(column[2]) * stod(column[1]);
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);

    
    // {(handling, 1), (delivery, 5), (tax, 3)}
    // {(delivery, 4), (handling, 2), (tax, 3)}
}

