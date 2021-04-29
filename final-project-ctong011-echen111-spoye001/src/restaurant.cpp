#include "../header/item.hpp"
#include "../header/restaurant.hpp"
#include <iostream>
#include <vector>
using namespace std;

Restaurant::Restaurant(string name) : name(name) {}

void Restaurant::addItem(Item* item) {
    order.push_back(item);
    subtotal += item->getPrice();
}

void Restaurant::removeItem(Item* item) {
    for (unsigned int i = 0; i < order.size(); i++) {
        if (order.at(i) == item) {
            subtotal -= item->getPrice();
	        order.erase(order.begin() + i);
            return;
        }
    }
}

Item* Restaurant::getItem(int index) const {
    if (index >= 0 && index < order.size()) {
        return order.at(index);
    }
    else {
        return nullptr;
    }
}

double Restaurant::getSubtotal() const {
    return subtotal;
}

void Restaurant::display() const {
    cout << "Restaurant: " << name << endl;
    cout << "ORDER" << endl;
    for (unsigned int i = 0; i < order.size(); i++) {
	order.at(i)->displayItem();
    }
    cout << endl;
    cout << "SUBTOTAL - $" << subtotal << endl;
}

string Restaurant::getRestaurantName() const{
    return name;
}

vector<Item *> Restaurant::getOrder() const{
    return order;
}

void Restaurant::createMenu(){
    ifstream fin;
    stringstream ss;
	//string a = ".csv"; string b = "DoorDash"; string c = b+a;
	//cout << c << endl;
//string s = ".csv";    
 //string y = "CSV/DoorDash - " + this->name; 
	//cout <<"str: " <<  y+s << endl;
	//cout << "string" << endl;
    //ss << s;    
ss << "CSV/DoorDash - " << this->name << ".csv"; 
    string FILENAME = ss.str();
    fin.open(FILENAME);
    ss.str("");
    ss.clear();
    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector <string> tempV;
    string line, word, temp;

    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        tempV.push_back(word);
    }
    if (tempV.at(0) == "Item"){
        tempV.erase(tempV.begin());
        for (int i = 0; i < tempV.size(); i++){
            Item* item = new Item(tempV.at(i), -1);
            menu.push_back(item);
        }
    }
    ss.str("");
    ss.clear();
    tempV.clear();
    // while (fin >> temp){
    //     getline(fin, line);
    //     stringstream ss(line);

    //     while (getline(ss, word, ',')){
    //         tempV.push_back(word);
    //     }
    //     for (int i = 0; i < tempV.size(); i++){
    //         Item* item = new Item(tempV.at(i), -1);
    //         menu.push_back(item);
    //     }
    //     tempV.clear();
    //     break;
    // }
    getline(fin,line);
    ss << line;
    while (getline(ss, word, ',')){
        tempV.push_back(word);
    }
    if (tempV.at(0) == "Price"){
        tempV.erase(tempV.begin());
        for (int i = 0; i < tempV.size(); i++){
            menu.at(i)->setPrice(stod(tempV.at(i)));
        }
    }
//     while (fin >> temp){
//         getline(fin, line);

//         stringstream ss(line);

//         while (getline(ss, word, ',')){
//             tempV.push_back(word);
//         }

//         for (int i = 0; i < tempV.size(); i++){
//             menu.at(i)->setPrice(stod(tempV.at(i)));
//         }
//         tempV.clear();
//         break;
//     }
//     fin.close();
}

void Restaurant::printMenu(){
    for (int i = 0; i < menu.size(); i++){
        string food = menu.at(i)->getName();
        double price = menu.at(i)->getPrice();
        cout << i << " - " <<  food << ": $" << price << endl;
    }
}

Item* Restaurant::getMenuItem(int index) const{
    if (index >= 0 && index < menu.size()) {
        return menu.at(index);
    }
    else {
        return nullptr;
    }
}
