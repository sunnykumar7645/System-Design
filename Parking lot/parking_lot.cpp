#include <bits/stdc++.h>
using namespace std;

enum class VehicleType { 
    Car, 
    Bike, 
    Truck 
};

class EntryGate{
private:
    int gateNumber;

public:
    void parkVehicle(){
        cout<<"Vehicle parked at gate number "<<gateNumber<<endl;
    }
};

class ExitGate{
private:
    int gateNumber; 

public:
    void unParkVehicle(){
        cout<<"Vehicle unparked at gate number "<<gateNumber<<endl;
    }
};

class ParkingLot{
protected:
    vector<ParkingSpot> parkingSpots;
    map<string, ParkingTicket> activeTickets;
    // PricingStrategy* pricingStrategy;
public:
    void parkVehicle(Vehicle* vehicle, int gateNumber){
        // Find an available parking spot
        // Generate a parking ticket
        // Update activeTickets
    }

    void unParkVehicle(string ticketId, int gateNumber){
        // Validate the ticket
        // Calculate parking fee using pricing strategy
        // Update activeTickets
    }

};

class ParkingSpot{
protected:
    int spotId;
    string spotType; // e.g., "Compact", "Large", "Handicapped"
    bool status; // true if occupied, false if available
    string currentVehicle; // e.g., "Car", "Motorcycle", "Truck"
public:
    void assignVehicle(string vehicleType){
        currentVehicle = vehicleType;
        status = true;
    }

    void removeVehicle(){
        currentVehicle = "";
        status = false;
    }
    bool isAvailable(){
        return !status;
    }
};

class Vehicle{
protected:
    string vehicleNumber; // e.g., license plate number
public:
    Vehicle(string number) : vehicleNumber(number) {}

    string getVehicleNumber(){
        return vehicleNumber;
    }

    virtual VehicleType getVehicleType() const = 0; // Pure virtual function to be implemented by derived classes

};

class Car : public Vehicle{
public:    
    Car(string number) : Vehicle(number) {}  
    
    VehicleType getVehicleType() const override {
        return VehicleType::Car;
    }
};

class Bike : public Vehicle{
public:    
    Bike(string number) : Vehicle(number) {}

    VehicleType getVehicleType() const override {
        return VehicleType::Bike;
    }
};

class Truck : public Vehicle{
public:    
    Truck(string number) : Vehicle(number) {}
    VehicleType getVehicleType() const override {
        return VehicleType::Truck;
    }
};

class VehicleFactory{
public:
    static unique_ptr<Vehicle> createVehicle(VehicleType type, string number){
         switch (type) {
            case VehicleType::Car:
                return make_unique<Car>(number);
            case VehicleType::Bike:
                return make_unique<Bike>(number);
            case VehicleType::Truck:
                return make_unique<Truck>(number);
            default:
                return nullptr;
        }
    }
};




class PaymentStrategy{

public:
    virtual double calculateFee(ParkingTicket ticket) = 0;
};

class HourlyPaymentStrategy : public PaymentStrategy{   

public:
    double calculateFee(ParkingTicket ticket) override {
        // Implement hourly fee calculation logic
        return 0.0; // Placeholder
    }

};

class DailyPaymentStrategy : public PaymentStrategy{    
public:
    double calculateFee(ParkingTicket ticket) override {
        // Implement daily fee calculation logic
        return 0.0; // Placeholder
    }

};

class ParkingTicket{
protected:
    string ticketId;
    ParkingSpot spot;
    time_t entryTime;
    time_t exitTime;
    int entryGateNumber;
    int exitGateNumber;
    bool status; // true if active, false if exited

};


int main(){


    return 0;
}