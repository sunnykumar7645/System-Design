#include<bits/stdc++.h>

using namespace std;

/*=======================================================
    Notification System Design in C++
  =======================================================
*/

class INotification{
public:
    virtual string getContent() = 0;
    virtual ~INotification() = default;
};
class SimpleNotification: public INotification{
private:
    string text;
public:
    SimpleNotification(string text): text(text){}
    string getContent() override{
        return text + ": message content."; ;
    }
};

class INotificationDecorator: public INotification{
protected:
    INotification* notification;
public:
    INotificationDecorator(INotification* notification): notification(notification){}
    virtual ~INotificationDecorator(){
        delete notification;
    }
};
class TimestampDecorator: public INotificationDecorator{
public:
    TimestampDecorator(INotification* notification): INotificationDecorator(notification){}
    string getContent() override{
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        string timestamp = ctime(&now_time);
        timestamp.pop_back(); // Remove newline character
        return "[" + timestamp + "] " + notification->getContent();
    }
};

class SignatureDecorator: public INotificationDecorator{
private:
    string signature;
public:
    SignatureDecorator(INotification* notification, string signature): INotificationDecorator(notification), signature(signature){}
    
    string getContent() override{
        return notification->getContent() + " -- " + signature;
    }
};

/*========================================================
    Observer Pattern for Notification System
  =======================================================
*/

class IObserver{
public:
    virtual void update() = 0;
    virtual ~IObserver() = default;
};
class IObservable{
public:
    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObservable() = default;
};

class NotificationObservable: public IObservable{
private:
    vector<IObserver*> observers;
    INotification* currentNotification;
public:
    NotificationObservable(){
        currentNotification = nullptr;
    }
    void addObserver(IObserver* observer) override{
        observers.push_back(observer);
    }
    void removeObserver(IObserver* observer) override{
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyObservers() override{
        for(auto observer : observers){
            observer->update();
        }
    }
    void setNotification(INotification* notification){
        if(currentNotification != nullptr){
            delete currentNotification;
        }
        currentNotification = notification;
        notifyObservers();
    }   

    INotification* getNotification(){
        return currentNotification;
    }
    string getNotificationContent(){
        if(currentNotification != nullptr){
            return currentNotification->getContent();
        }
        return "No notification set.";
    }

    ~NotificationObservable(){
        if(currentNotification != nullptr){
            delete currentNotification;
        }
    }

};  

class Logger : public IObserver{
private:
    NotificationObservable* notificationObservable;
public:
    Logger(NotificationObservable* notificationObservable){
        this->notificationObservable = notificationObservable;
    }
    void update() override{
        cout<<"Logger: Notification updated.\n"<<notificationObservable->getNotificationContent()<<endl;
    }
};

/*========================================================
    Strategy Pattern for Notification System
=======================================================
*/
class INotificationStrategy{
public:
    virtual void sendNotification(string message) = 0;
    virtual ~INotificationStrategy() = default;
};

class EmailNotificationStrategy: public INotificationStrategy{
private:
    string emailAddress;
public:
    EmailNotificationStrategy(string emailAddress): emailAddress(emailAddress){}
    void sendNotification(string message) override{
        cout<<"Sending Email to "<<emailAddress<<": "<<message<<endl;
    }
};

class SMSNotificationStrategy: public INotificationStrategy{
private:    
    string phoneNumber;
public:
    SMSNotificationStrategy(string phoneNumber): phoneNumber(phoneNumber){}
    
    void sendNotification(string message) override{
        cout<<"Sending SMS to "<<phoneNumber<<": "<<message<<endl;
    }
};

class PopUpNotificationStrategy: public INotificationStrategy{
public:
    void sendNotification(string message) override{
        cout<<"Showing Pop-up: "<<message<<endl;
    }
};  

class NotificationEngine: public IObserver{
private:
    NotificationObservable* notificationObservable;
    vector<INotificationStrategy*> strategies;
public:
    NotificationEngine(NotificationObservable* notificationObservable){
        this->notificationObservable = notificationObservable;
    }

    void addNotificationStrategy(INotificationStrategy* strategy){
        strategies.push_back(strategy);
    }

   void update() override{
        string message = notificationObservable->getNotificationContent();
        for(auto strategy : strategies){
            strategy->sendNotification(message);
        }
    }

    ~NotificationEngine(){
        for(auto strategy : strategies){
            delete strategy;
        }
    }
};  

/*========================================================
     Notification Service System
=======================================================
*/
class NotificationService{
private:
    NotificationObservable* observable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService(){
        observable = new NotificationObservable();
    }   

public:
    static NotificationService* getInstance(){
        if(instance == nullptr){
            instance = new NotificationService();
        }
        return instance;
    }   
    NotificationObservable* getObservable(){
        return observable;
    }

    void sendNotification(INotification* notification){
        notifications.push_back(notification);
        observable->setNotification(notification);
    }

    ~NotificationService(){
        delete observable;
        
    }

};

NotificationService* NotificationService::instance = nullptr;






int main(){
    cout<<"Notification System Design Example in C++"<<endl;

    NotificationService* service = NotificationService::getInstance();
    NotificationObservable *notificationObservable = service->getObservable();
    Logger *logger = new Logger(notificationObservable);

    NotificationEngine *engine = new NotificationEngine(notificationObservable);

    engine->addNotificationStrategy(new EmailNotificationStrategy("sunnny@gmial.com"));
    engine->addNotificationStrategy(new SMSNotificationStrategy("123-456-7890"));
    engine->addNotificationStrategy(new PopUpNotificationStrategy());
     
    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(engine);

    INotification* notification1 = new SimpleNotification("Order has been placed successfully!.");
    notification1 = new TimestampDecorator(notification1);
    notification1 = new SignatureDecorator(notification1, "Best regards, E-commerce Team");
    service->sendNotification(notification1);
    
    delete logger;
    delete engine;

    return 0;
}