#include "../header/timebreakdown.hpp"
#include "../header/uetimebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

UETimeBreakdown::UETimeBreakdown() {}

void UETimeBreakdown::collectTimeMetaData(Restaurant *rest) {
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
    
    // calculate time needed to prepare food
    int foodPrep = rest->getOrder().size() * 2;
    Time cooking("Cooking", foodPrep);
    timeBreakdown.push_back(cooking);

    int deliveryTime = stoi(row[4]);
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(delivery);
}
