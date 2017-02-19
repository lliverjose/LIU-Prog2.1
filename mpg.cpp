//
//  mpg.cpp
//  Prog2.1
//
//  Created by LLiver Jose on 2/18/17.
//  Copyright © 2017 @LIU. All rights reserved.
//

#include <iostream>
//#include <algorithm>
//#include <cctype>
#include <iomanip>
#include <string>
#include "mpg.h"

using namespace std;

struct Node {
    GasMileage mpg{};
    Node* next;
};

char change_case (char c) {
    return tolower(c);
}
typedef Node* NodePtr;

void AddToList (string address, double miles, double gas, NodePtr &hdList);
void PrintList (NodePtr hdList);

int main(int argc, const char * argv[]) {
    
    string answer;
    string tripAddress;
    double mileage{0};
    double gas{0};
    
    NodePtr hdList = NULL;
    
    while (true) {
        cout << "Calculate a trip mpg? ";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), change_case);
        
        if (answer == "n") {
            break;
        }
        
        cin.ignore();
        /*
         for (int i=0; i<3; i++) {
         cout << "Enter trip address: ";
         getline(cin, tripAddress);
         
         mileage += 10;
         gas += 20;
         AddToList (tripAddress, mileage, gas, hdList);
         }
         */
        
        if (answer == "y") {
            cout << "Enter trip address: ";
            getline(cin, tripAddress);
            //tripAddress = "Trip Address";
            cout << "Enter trip mileage: ";
            cin >> mileage;
            cout << "Enter gas used: ";
            cin >> gas;
            AddToList (tripAddress, mileage, gas, hdList);
        }
        
    }
    
    // Calculate the total mpg used
    PrintList(hdList);
    
    return 0;
}

void AddToList (string address, double mileage, double gas, NodePtr &hdList) {
    NodePtr newNode = new Node;
    newNode->mpg.setTripAddress(address);
    newNode->mpg.setMileage(mileage);
    newNode->mpg.setGas(gas);
    newNode->next = hdList;
    hdList = newNode;
}

void PrintList (NodePtr hdList){
    double mileage{0};
    double gas{0};
    double total{0};
    cout << setprecision(2);
    cout << "Trip Address\tGas\t\tMileage\tMPG" << endl;
    for (NodePtr ptr = hdList; ptr != NULL; ptr = ptr->next) {
        gas += ptr->mpg.getGas();
        mileage += ptr->mpg.getMileage();
        cout << ptr->mpg.getTripAddress() << "\t\t\t";
        cout << ptr->mpg.getGas() << "\t\t";
        cout << ptr->mpg.getMileage() << "\t\t";
        cout << ptr->mpg.getGas() * ptr->mpg.getMileage() << endl;
    }
    total = mileage / gas;
    cout << "Total MPG for all trips = " << total << endl;
}

// comment

