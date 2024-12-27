#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include "car.hpp"
#include "bike.hpp"
#include<iostream>
using namespace std;

class VehicleFactory{

    public:
        // we created this function as static because we don't need to create object of this class 
        static Vehicle* getVehicle(string vehicleType);
};




#endif 