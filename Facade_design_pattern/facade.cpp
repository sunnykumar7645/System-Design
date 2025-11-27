#include<bits/stdc++.h>
using namespace std;

class Cpu{
public:
    void processData(){
        cout<<"CPU is processing data"<<endl;
    }
};
class Memory{
public:
    void loadData(){
        cout<<"Memory is loading data"<<endl;
    }
};
class HardDrive{
public:
    void readData(){
        cout<<"Hard Drive is reading data"<<endl;       
    }
};
class ComputerFacade{
private:
    Cpu* cpu;
    Memory* memory;
    HardDrive* hardDrive;
public:
    ComputerFacade(){
        cpu = new Cpu();
        memory = new Memory();
        hardDrive = new HardDrive();
    }
    void startComputer(){
        cout<<"Starting Computer..."<<endl;
        hardDrive->readData();
        memory->loadData();
        cpu->processData();     
        cout<<"Computer Started Successfully!"<<endl;
    }
};  

int main(){
    cout<<"Facade Design Pattern Example in C++"<<endl;
    ComputerFacade* computer = new ComputerFacade();
    computer->startComputer();
    return 0;
}