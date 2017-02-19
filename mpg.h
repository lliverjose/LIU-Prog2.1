//
//  mpg.h
//  Prog2.1
//
//  Created by LLiver Jose on 2/18/17.
//  Copyright © 2017 @LIU. All rights reserved.
//

#include <string>
#ifndef mpg_h
#define mpg_h

using namespace std;

class GasMileage {
public:
    // Account constructor w/o parameters
    GasMileage() {};
    
    GasMileage(string a, double m, double g)
    : tripAddress{a} {
        if (m > 0) {
            miles += m;
        }
        if (g > 0) {
            gas += g;
        }
    }
    
    // function that sets the trip address
    void setTripAddress(string a) {
        tripAddress = a;
    }
    // function that sets the miles
    void setMileage(double m) {
        miles = m;
    }
    // function that sets the galon
    void setGas(double g) {
        gas = g;
    }
    
    // function that sets the trip address
    string getTripAddress() {
        return tripAddress;
    }
    // function that returns the miles
    double getMileage() {
        return miles;
    }
    // function that sets the galon
    double getGas() {
        return gas;
    }
    
private:
    string tripAddress{0};
    double miles{0};
    double gas{0};
};
#endif /* mpg_h */
