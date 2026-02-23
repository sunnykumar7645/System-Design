#include<bits/stdc++.h>     
using namespace std;

class Vehicle{
public:
    virtual void drive()=0;
    virtual ~Vehicle()=default;
};  

class Car: public Vehicle{
public:     
    void drive() override{
        cout<<"Driving a car"<<endl;
    }
};      
class Bike: public Vehicle{
public:    
    void drive() override{
        cout<<"Riding a bike"<<endl;
    }
};  
class VehicleFactory{
public:    
    static Vehicle* createVehicle(const string& type){
        if(type == "car"){
            return new Car();
        } else if(type == "bike"){
            return new Bike();      
        } else {
            throw invalid_argument("Unknown vehicle type");
        }
    }
};


int main(){
    cout<<"Factory Design Pattern Example in C++"<<endl;
    Vehicle* myVehicle = VehicleFactory::createVehicle("car");
    myVehicle->drive();
    return 0;
}   