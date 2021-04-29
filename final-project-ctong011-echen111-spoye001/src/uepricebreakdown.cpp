#include "../header/pricebreakdown.hpp"
#include "../header/uepricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

UEPriceBreakdown::UEPriceBreakdown() {}

void UEPriceBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/UberEats - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> row; 
    string line, word, temp, colname;

    while(fin >> temp){
        row.clear();
        getline(fin,line);
        istringstream ss(line);
        //checks first phrase in each column
        while(getline(ss, colname, ',')){
            //if name matches restaurant name, push row info into vector row
            if (colname == rest->getRestaurantName()){
                while(ss >> word){
                    row.push_back(word);    
                    if(ss.peek() == ',') ss.ignore();
                }
            }
        }
    }

    fin.close();
    
    double subtotal = rest->getSubtotal();
    //small order fee
    double smallFee = 3;
    //if subtotal(before tax) < $15, apply small order fee
    if(subtotal < 15){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(small);
    }
    double tFee = 0.0872*subtotal;
    //tax = 108.72 x cost
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //service fee = handling x num Items
     //service fee = 15%    
    double servFee = subtotal * 1.15;
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery Fee = fee x distance
    double dFee = stod(row[2]) * stod(row[1]);
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    
}
