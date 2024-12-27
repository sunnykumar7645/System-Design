#include<iostream>
#include"bike.hpp"
#include"car.hpp"
using namespace std;

int main(){

    string vehicleType;
    cin>>vehicleType;
    Vehicle* vehicle;
    // This code is titecouled, whenever we need to add the another vehicle we have add if else condition and run the file again n again
    if(vehicleType == "car"){
        vehicle = new Car();
    }
    else if(vehicleType == "bike"){
        vehicle = new Bike();
    }
    vehicle->createVehicle();
    return 0;
}