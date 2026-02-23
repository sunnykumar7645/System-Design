#include<bits/stdc++.h>

using namespace std;

class PhoneCharger{
public:
    virtual void chargePhone()=0;
};

class ElectricSocket{
public:
    virtual void provideElectricity()=0;

};
class IndianSocket: public ElectricSocket{
public:
    void provideElectricity() override{
        cout<<"Providing electricity at 220V from Indian Socket"<<endl;
    }
};  

class IndianToUSAdapter: public PhoneCharger{
private:
    ElectricSocket* socket;
public:

    IndianToUSAdapter(ElectricSocket* sock): socket(sock) {}


    void chargePhone() override{
        cout<<"adapter converting 220V to 5V for Indian Socket"<<endl;
        socket->provideElectricity();
        cout<<"Adapter converting 220V to 110V for US Phone Charger"<<endl;
    }

};

int main(){
    cout<<"Adapter Design Pattern Example in C++"<<endl;
    ElectricSocket* indianSocket = new IndianSocket();
    PhoneCharger* adapter = new IndianToUSAdapter(indianSocket);
    adapter->chargePhone();

    return 0;
}
