#include <bits/stdc++.h>
using namespace std;

class Singleton {
    private:
        Singleton(){
            // cout << "Singleton class constructor called." << endl;
        } // Private constructor to prevent instantiation

    public:
        // copy constructor and assignment operator are deleted to prevent copying of the instance
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        static Singleton* getInstance(){
            static Singleton* instance;
            return instance;
        }
        void showInstance(){
            cout << "This is a singleton instance." << endl;
        }
};



int main(){
    Singleton* s1 = Singleton::getInstance();
    s1->showInstance();
    Singleton* s2 = Singleton::getInstance();
    s2->showInstance();
    if(s1 == s2)
        cout << "Both s1 and s2 point to the same instance." << endl;


    return 0;
}