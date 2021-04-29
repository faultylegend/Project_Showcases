#include "header/category.hpp"
#include "header/factory.hpp"
#include "header/fooditem.hpp"
#include "header/item.hpp"
#include "header/restaurant.hpp"
#include "header/strategy.hpp"
#include "header/timestrategy.hpp"
#include "header/pricestrategy.hpp"
#include "header/tag.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;
int restaurant;
int option = 1;
vector <string> restList;

void mainMenu(){
    cout << "--Menu--" << endl;
    cout << "1. Check Menu" << endl;
    cout << "2. Add Food Item" << endl;
    cout << "3. Delete Food Item" << endl;
    cout << "4. View Order" << endl;
    cout << "0. Continue" << endl;
}

int main(){
    cout << "Welcome to NOM!" << endl;
    
    //display restaurant list
    string FILENAME = "CSV/RestaurantList.csv";
    ifstream fin;
    fin.open(FILENAME);
    string temp,line;
    while (getline(fin, line)){
        restList.push_back(line);
    }
    for (int i = 0; i < restList.size(); i++){
        cout << i + 1 << " - " << restList.at(i) << endl;
    }
    cout << endl;
    cout << "Please select the restaurant number you would like to eat at: ";
    cin >> restaurant;
    Restaurant* user = new Restaurant(restList.at(restaurant-1));
    user->createMenu();
    cout << "Now it is time to select your order!" << endl;
    while (option != 0){
        mainMenu();
        //display menu
        cin >> option;
        if (option == 0){
            break;
        }
        else if (option == 1){
            user->printMenu();
        }
        else if (option == 2){
            cout << "Enter the food item number you want: ";
            int itemNumber = 0;
            cin >> itemNumber;
            Item* item = user->getMenuItem(itemNumber);
            string choice = "y";
            cout << "Do you want to add tags to this food item? (y/n): ";
            cin >> choice;
            while (choice == "y"){
                if (choice == "y"){
                    cout << "Do you want to add a category(0) or sub category(1)? ";
                    int catChoice = -1;
                    cin >> catChoice;
                    if (catChoice == 0){
                        cout << "Enter Category Tag: ";
                        string category;
                        cin >> category;
                        item->addCategoryTag(category); 
                    }
                    else if (catChoice == 1) {
                        cout << "Enter Existing Category Tag: ";
                        string category;
                        cin >> category;
                        cout << "Enter Sub Category Tag: ";
                        string subCategory;
                        cin >> subCategory;
                        item->addCategoryTag(subCategory,category);
                    }
                }
                else{break;}
                cout << "Do you want to add another tag to this food item? (y/n): ";
                cin >> choice;
            }
            user->addItem(item);
        }
        else if(option == 3){
            for (int i = 0; i < user->getOrder().size(); i++)
            {
                cout << i << " - ";
                user->getOrder().at(i)->displayItem();
            }
            cout << endl;
            cout << "Enter the food item you want to remove: ";
            int itemNumber = 0;
            cin >> itemNumber;
            user->removeItem(user->getItem(itemNumber));
        }
        else if(option == 4){
            user->display();
        }
    }
    cout << endl;
    cout << "Do you want cheapest price(0) or fastest time (1)? ";
    cin >> option;

    //strategy
    if (option == 0){
        //price comparison
        Strategy* price = new PriceStrategy(user);
        price->compare();
    }

    if (option == 1){
        //time comparison
        Strategy* price = new TimeStrategy(user);
        price->compare();
    }

    return 1;
}
