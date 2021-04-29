#include "../header/pricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "../header/factory.hpp"
// #include "../header/pricebreakdown.hpp"
// #include "../header/uepricebreakdown.hpp"
// #include "../header/ddpricebreakdown.hpp"
// #include "../header/timebreakdown.hpp"
// #include "../header/uetimebreakdown.hpp"
// #include "../header/ddtimebreakdown.hpp"

UberEatsFactory::UberEatsFactory(Restaurant* rest) : Factory(rest) {}

void UberEatsFactory::createPriceBreakdown() {
    ifstream fin;
    fin.open("CSV/UberEats - Restaurant List.csv");
    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> row; 
    string line, word, temp, colname;
    stringstream ss;
    getline(fin,line);
    ss << line;
    for (int i = 0; i < 11; i++){
        while (getline(ss, word, ',')){
            row.push_back(word);
        }
        if (row.at(0) == rest->getRestaurantName()){
            break;
        }
        else{
            row.clear();
            getline(fin,line);
            ss.str("");
            ss.clear();
            ss << line;
        }
    }

    // while(fin >> temp){
    //     row.clear();
    //     getline(fin,line);
    //     istringstream ss(line);
    //     //checks first phrase in each column
    //     while(getline(ss, colname, ',')){
    //         //if name matches restaurant name, push row info into vector row
    //         if (colname == rest->getRestaurantName()){
    //             while(ss >> word){
    //                 row.push_back(word);    
    //                 if(ss.peek() == ',') ss.ignore();
    //             }
    //         }
    //     }
    // }
    
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
    double servFee = subtotal * 0.15;
    cout << subtotal << endl;
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery Fee = fee x distance
    double dFee = stod(row[2]) * stod(row[1]);
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    // pbd = new UEPriceBreakdown();
    // return pbd;
}

void UberEatsFactory::createTimeBreakdown() {
    ifstream fin;
    fin.open("CSV/UberEats - Restaurant List.csv");
    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> row; 
    string line, word, temp, colname;
    stringstream ss;
    getline(fin,line);
    ss << line;
    for (int i = 0; i < 11; i++){
        while (getline(ss, word, ',')){
            row.push_back(word);
        }
        if (row.at(0) == rest->getRestaurantName()){
            break;
        }
        else{
            row.clear();
            getline(fin,line);
            ss.str("");
            ss.clear();
            ss << line;
        }
    }
    // for (auto i : row) {
    //     cout << i << endl;
    // }
    // while(fin >> temp){
    //     row.clear();
    //     getline(fin,line);
    //     istringstream ss(line);
    //     //checks first phrase in each column
    //     while(getline(ss, colname, ',')){
    //         //if name matches restaurant name, push row info into vector row
    //         if (colname == rest->getRestaurantName()){
    //             while(ss >> word){
    //                 row.push_back(word);    
    //                 if(ss.peek() == ',') ss.ignore();
    //             }
    //         }
    //     }
    // }

    fin.close();
    
    // calculate time needed to prepare food
    int foodPrep = rest->getOrder().size() * 2;
    Time cooking("Cooking", foodPrep);
    timeBreakdown.push_back(cooking);
    // cout << "about to stoi" << endl;
    // string s = row.at(3);
    // cout << s << endl;
    int deliveryTime = stoi(row.at(3));
    // cout << deliveryTime << endl;
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(delivery);
    // tbd = new UETimeBreakdown();
    // return tbd;
}

// void UberEatsFactory::createRestaurantList() {

// }

DoorDashFactory::DoorDashFactory(Restaurant* rest) : Factory(rest) {}

void DoorDashFactory::createPriceBreakdown() {
    ifstream fin;
    fin.open("CSV/DoorDash - Restaurant List.csv");
    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> column; 
    string line, word, temp;
    stringstream ss;
    // int colIdx = 0;
    // while(ss >> word){
    //     if(word == rest->getRestaurantName()){
    //         column.push_back(word);
    //         break;
    //     }
    //     else{
    //         if(ss.peek() == ',') ss.ignore();
    //         colIdx++;
    //     }
    // }
    // while(getline(fin,line)){
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        column.push_back(word);
    }
    int index = 0;
    for(auto i : column){
        if(i != rest->getRestaurantName()){
            index++;
        }
        else{break;}
    }
    ss.str("");
    ss.clear();
    vector <string> distance;
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        distance.push_back(word);
    }
    ss.str("");
    ss.clear();
    vector <string> Dfee;
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        Dfee.push_back(word);
    }
    ss.str("");
    ss.clear();
    vector <string> Sfee;
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        Sfee.push_back(word);
    }
        // int columnIdx = 0;
        // while(ss >> word){
        //     if(columnIdx == colIdx){
        //         column.push_back(word);
        //         if(ss.peek() == ',') ss.ignore();
        //     }
        //     else{
        //         columnIdx++;
        //     }
        // }


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
    double servFee = subtotal * stod(Sfee.at(index));
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery fee = fee x distance
    double dFee = stod(distance.at(index)) * stod(distance.at(index));
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    // pbd = new DDPriceBreakdown();
    // return pbd;
}

void DoorDashFactory::createTimeBreakdown() {
    ifstream fin;
    fin.open("CSV/DoorDash - Restaurant List.csv");
    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> column; 
    string line, word, temp;
    stringstream ss;

    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        column.push_back(word);
    }
    int index = 0;
    for(auto i : column){
        if(i != rest->getRestaurantName()){
            index++;
        }
        else{break;}
    }
    ss.str("");
    ss.clear();

    getline(fin,line);
    ss << line;

    ss.str("");
    ss.clear();

    getline(fin,line);
    ss << line;

    ss.str("");
    ss.clear();

    getline(fin,line);
    ss << line;

    ss.str("");
    ss.clear();

    vector <string> time;
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        time.push_back(word);
    }
    // int colIdx = 0;
    // while(ss >> word){
    //     if(word == rest->getRestaurantName()){
    //         column.push_back(word);
    //         break;
    //     }
    //     else{
    //         if(ss.peek() == ',') ss.ignore();
    //         colIdx++;
    //     }
    // }
    // while(getline(fin,line)){
    //     int columnIdx = 0;
    //     while(ss >> word){
    //         if(columnIdx == colIdx){
    //             column.push_back(word);
    //             if(ss.peek() == ',') ss.ignore();
    //         }
    //         else{
    //             columnIdx++;
    //         }
    //     }
    // }

    fin.close();

    // calculate time needed to prepare food
    int foodPrep = (rest->getOrder().size()) * 2;
    Time cooking("Cooking", foodPrep);
    timeBreakdown.push_back(cooking);
    // cout << time.at(index);
    int deliveryTime = stoi(time.at(index));
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(delivery);
    // tbd = new DDTimeBreakdown();
    // return tbd;
}
// void DoorDashFactory::createRestaurantList() {

// }
