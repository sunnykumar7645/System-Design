#include<iostream>

using namespace std;

// Interface or abstract class for walking 
class Walkable{
public:
    virtual void walk() = 0;
};

// concreate class
class NormalWalk : public Walkable{

    void walk(){
        cout<<"Robot can walk normally"<<endl;
    }

};

class NoWalk: public Walkable{
public:

    void walk(){
        cout<<"Robot can't walk"<<endl;
    }
};

// interface or abstract class
class Talkable{
public:
    virtual void talk() = 0;
};

class NormalTalk : public Talkable{
public:

    void talk(){
        cout<<"Robot can talk normally"<<endl;
    }

};

class NoTalk : public Talkable{
public:

    void Talk(){
        cout<<"Robot can't talk"<<endl;
    }
};


class Flyable{
public:
    virtual void fly() = 0;
};

class NoramlFly : public Flyable{
public:
    void fly(){
        cout<<"Robot can fly normally"<<endl;
    }
};

class NoFly : public Flyable{
public:
    void fly(){
        cout<<"Robot can't fly"<<endl;
    }
};

class Robot{
protected:
    Walkable *walkbehavior;
    Talkable *talkbehavior;
    Flyable  *flybehavior;
public:
    Robot(Walkable *w, Talkable *t, Flyable *f) : walkbehavior(w), talkbehavior(t), flybehavior(f){

    }

    void walk(){
        walkbehavior->walk();
    }
    void talk(){
        talkbehavior->talk();
    }
    void fly(){
        flybehavior->fly();
    }

    virtual void projection() = 0;
};
class CompaionRobot : public Robot{
public:
    CompaionRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f){}
    void projection(){
        cout<<"Robot is project the data"<<endl;
    }
};



int main(){

    Robot * r1 = new CompaionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    r1->walk();
    r1->talk();
    r1->fly();
    r1->projection();


    return 0;
}