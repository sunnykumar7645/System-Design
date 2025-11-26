#include<bits/stdc++.h>
using namespace std;

// Observer Design Pattern Example
class Observer {
public:
    virtual void update(const string &message_from_subject) = 0;
};


class subject {
public:
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
};




class youtubeChannel : public subject {
private:
    vector<Observer *> observers_list;
    string youtubeChannelName;

public:
    youtubeChannel(string youtubeChannelName) {
        this->youtubeChannelName = youtubeChannelName;
    }
    void attach(Observer *observer) override {
        observers_list.push_back(observer);
        cout << "Subscriber"<<observer<<"is added." << endl;
    }
    void detach(Observer *observer) override {
        observers_list.erase(remove(observers_list.begin(), observers_list.end(),
         observer), observers_list.end());
        cout << "Subscriber"<<observer<<"is removed." << endl;
    }
    void notify() override {
        for (Observer *observer : observers_list) {
            observer->update( "New video uploaded by " + youtubeChannelName + "!" );
        }
    }
};

class Subscriber : public Observer {
    public:
    void update(const string &message_from_subject) override {
        cout << "Notification received: " << message_from_subject << endl;
    }
};



int main(){
    cout<<"Observer Design Pattern Example"<<endl;
    youtubeChannel *channel = new youtubeChannel("SampleChannel");
    Subscriber *sub1 = new Subscriber();
    Subscriber *sub2 = new Subscriber();
    channel->attach(sub1);
    channel->attach(sub2);
    channel->notify();
    Subscriber *sub3 = new Subscriber();
    channel->attach(sub3);
    channel->notify();  
    channel->detach(sub2);
    channel->notify();

    return 0;
}