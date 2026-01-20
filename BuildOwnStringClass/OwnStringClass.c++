#include<iostream>
#include<cstring>

using namespace std;

class String{
private:
    char *str;
    unsigned int len;

public:
    String() : str(nullptr), len(0) {
    }

    String(const char *s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    String(const String &other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    String& operator=(const String& s){
        if(this != &s){
            delete[] str;
            len = s.len;
            str = new char[len + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    unsigned int length() const {
        return len;
    }





    ~String() {
        delete[] str;
    }


};


int main(){

    int data = 8;

    cout<<"This class is created by sunny kumar";

    return 0;
}