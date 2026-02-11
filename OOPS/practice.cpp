#include<bits/stdc++.h>
using namespace std;    
class Animal{
    public:
    Animal(){
        cout<<"Animal cont ..."<<endl;
    }
    virtual ~Animal(){
     cout<<"Animal dest..."<<endl;
    }
};

class Dog:public Animal{

    public:
    Dog(){
        cout<<"Dog const..."<<endl;
    }
    ~Dog(){
        cout<<"Dog dest..."<<endl;
    }
};
// class Cat:public Animal{

//     public:
//     Cat(){
//         cout<<"Cat const..."<<endl;
//     }

//     ~Cat(){
//         cout<<"Cat dest..."<<endl;
//     }
// };



int main(){

    Animal *a1=new Dog();
    // Animal *a2=new Cat();
    delete a1;
    


    return 0;
}