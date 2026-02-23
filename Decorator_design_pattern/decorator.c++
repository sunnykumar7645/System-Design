#include<bits/stdc++.h>

using namespace std;    

class Character{
public:
    virtual string getAbility() = 0;
    virtual ~Character() = default;
};
class BasicCharacter: public Character{
public:
    string getAbility() override{
        return "Basic Character";
    }
    
};

class CharacterDecorator: public Character{
protected:
    Character* character;
public:
    CharacterDecorator(Character* character): character(character){}
    string getAbility() override{
        return character->getAbility();
    }
};

class StrengthDecorator: public CharacterDecorator{
public:    
    StrengthDecorator(Character* character): CharacterDecorator(character){}
    
    string getAbility() override{
        return CharacterDecorator::getAbility() + " + Strength";
    }
};
class SpeedDecorator: public CharacterDecorator{
public:    
    SpeedDecorator(Character* character): CharacterDecorator(character){}
    string getAbility() override{
        return CharacterDecorator::getAbility() + " + Speed";
    }
};


int main(){
    cout<<"Decorator Design Pattern Example in C++"<<endl;

    Character* character = new BasicCharacter();
    cout<<character->getAbility()<<endl;
    character = new StrengthDecorator(character);
    cout<<character->getAbility()<<endl;
    character = new SpeedDecorator(character);
    cout<<character->getAbility()<<endl;
      
    return 0;
}