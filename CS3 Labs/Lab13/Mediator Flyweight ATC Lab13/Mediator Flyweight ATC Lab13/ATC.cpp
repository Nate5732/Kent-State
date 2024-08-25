// Nathon Iadimarco
// Lab13 Mediator Flyweight ATC
// mediator-based air traffic control

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <map>

// for timed sleep
#include <thread>
#include <chrono>


using std::cout; using std::cin; using std::endl;
using std::string; using std::map;

enum class airlines {Delta, United, JetBlue, AirFrance, KLM, Aeroflot, Lufthansa};

// Abstract Flyweight
class Logo {
public:
    virtual string image() = 0;
};

// Concrete Flyweights (Logos)
class Delta: public Logo {
public:
    string image() override {return "DELTA";}
};

class United: public Logo {
public:
    string image() override {return "UNITED";}
};

class JetBlue: public Logo {
public:
    string image() override {return "JETBLUE";}
};

class AirFrance: public Logo {
public:
    string image() override {return "AIRFRANCE";}
};

class KLM: public Logo {
public:
    string image() override {return "KLM";}
};

class Aeroflot: public Logo {
public:
    string image() override {return "AEROFLOT";}
};

class Lufthansa: public Logo {
public:
    string image() override {return "LUFTHANSA";}
};

// Academy factory
class Academy{
public:
    static Logo* makeLogo(airlines a){
        if (logos.find(a) == logos.end()) {
            switch(a) {
                case airlines::Delta:
                    // Delta lands/takes off
                    logos[a] = new Delta;
                    break;
                case airlines::United:
                    // United lands/takes off
                    logos[a] = new United;
                    break;
                case airlines::JetBlue:
                    // JetBlue lands/takes off
                    logos[a] = new JetBlue;
                    break;
                case airlines::AirFrance:
                    // AirFrance lands/takes off
                    logos[a] = new AirFrance;
                    break;
                case airlines::KLM:
                    // KLM lands/takes off
                    logos[a] = new KLM;
                    break;
                case airlines::Aeroflot:
                    // AeroFlot lands/takes off
                    logos[a] = new Aeroflot;
                    break;
                case airlines::Lufthansa:
                    // Lufthansa lands/takes off
                    logos[a] = new Lufthansa;
                    break;
            }
        }
        return logos[a];
    }
private:
    static std::map<airlines, Logo*> logos;
};
std::map<airlines, Logo*> Academy::logos;

// abstract mediator
class Controller{
public:
    virtual void join(class Flight*)=0;
    virtual void leave(class Flight*)=0;
    virtual void broadcast() = 0;
    virtual void observe() = 0;
};


// Client class
class Airplane {
public:
    Airplane(airlines a) {
        logo_ = Academy::makeLogo(a);
    }
    string report()const {
        return logo_->image();
    }
private:
    const string flight_;
    Logo* logo_;
};

// concrete mediator
// tower, runway clearance
class Tower: public Controller{
public:
    void join(class Flight*) override;
    void leave(class Flight*) override;
    void broadcast() override;
    void observe() override;
private:
    std::set<class Flight*> waiting_;
};



// abstract colleague
class Flight {
public:
    Flight(Controller *controller):controller_(controller), status_(Status::waiting){
        task_ = rand() % 2 ? Task::taxiing : Task::approaching;
        controller_->join(this);
    }
    void receive(const string &msg){
        if (msg.find(flightNo_) != string::npos || msg.find("all") != string::npos){
            if(msg.find("clear") != string::npos){
                cout << flightNo_ << " roger that, ";
                cout << (task_ == Task::taxiing ? "taking off" : "landing") << endl;
                
                if (flightNo_.find("Delta") != string::npos) { // Delta
                    Airplane* logo = new Airplane(airlines::Delta);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " "; // Outputs Logo
                    cout<<(task_ == Task::taxiing ? "takes off" : "lands") <<"....." <<endl;
                    delete logo;
                } else if (flightNo_.find("United") != string::npos) { // United
                    Airplane* logo = new Airplane( airlines::United);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                } else if (flightNo_.find("JetBlue") != string::npos) { // JetBlue
                    Airplane* logo = new Airplane(airlines::JetBlue);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                } else if (flightNo_.find("AirFrance") != string::npos) { // AirFrance
                    Airplane* logo = new Airplane(airlines::AirFrance);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                } else if (flightNo_.find("KLM") != string::npos) { // KLM
                    Airplane* logo = new Airplane(airlines::KLM);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                } else if (flightNo_.find("Aeroflot") != string::npos) { // Aeroflot
                    Airplane* logo = new Airplane(airlines::Aeroflot);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                } else if (flightNo_.find("Lufthansa") != string::npos) { // Lufthansa
                    Airplane* logo = new Airplane(airlines::Lufthansa);
                    string flightLogo = logo->report()+planeNum;
                    cout << "....." << flightLogo << " ";
                    cout << (task_ == Task::taxiing ? "takes off" : "lands") << "....." << endl;
                    delete logo;
                }
                status_ = Status::cleared;
                
            } else if(msg.find("status") != string::npos) {
                cout << flightNo_
                << (status_ == Status::waiting ? " waiting to " : " cleared to ")
                << (task_ == Task::taxiing ? "take off" : "land") << endl;
            } else
                cout << "Tower, this is " << flightNo_ << " please repeat." << endl;
        }
    }
    bool isCleared() const {return status_ == Status::cleared;}
    void proceed(){
        std::this_thread::sleep_for(std::chrono::seconds(rand()%3+1)); // wait a while
        cout << flightNo_
        << (task_ == Task::taxiing ? " took off" : " landed")
        << ". Have a good day!" << endl;
        controller_->leave(this);
    }
protected:
    string planeNum;
    string airline;
    string flightNo_;
    Controller *controller_;
    enum class Task {taxiing, approaching};  Task task_;
    enum class Status {waiting, cleared};    Status status_;
};


// concrete colleagues
class Airbus: public Flight{
public:
    Airbus(Tower *tower): Flight(tower){
        static const std::vector<string> companies =
        {"AirFrance", "KLM", "Aeroflot", "Lufthansa"};
        planeNum = std::to_string(rand() % 1000);
        airline = companies[rand() % companies.size()];
        flightNo_ = airline + planeNum;
        cout << flightNo_ << " requesting " << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
    }
};

class Boeing: public Flight{
public:
    Boeing(Tower *tower): Flight(tower){
        static const std::vector<string> companies =
        { "Delta", "United", "JetBlue" };
        planeNum = std::to_string(rand() % 1000);
        airline = companies[rand() % companies.size()];
        flightNo_ = airline + planeNum;
        cout << flightNo_ << " requesting "
        << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
    }
};


// member functions for Tower
void Tower::broadcast() {
    cout << "Tower: ";
    string msg;
    getline(cin,msg);
    if(!msg.empty())
        for(auto f: waiting_) f->receive(msg);
}


void Tower::observe() {
    auto findCleared = [](Flight *f){return f->isCleared();};
    
    auto toProceed = std::find_if(waiting_.begin(),waiting_.end(), findCleared);
    
    while (toProceed != waiting_.end()){ // found a cleared flight
        (*toProceed) -> proceed();
        toProceed = std::find_if(waiting_.begin(), waiting_.end(), findCleared);
        if(toProceed != waiting_.end())
            cout << "MAYDAY! MAYDAY! MAYDAY! " << endl; // more than a single flight cleared
    }
}


void Tower::join(Flight *f) {
    waiting_.insert(f);
}


void Tower::leave(Flight *f) {
    waiting_.erase(f);
    delete f;
}

int main(){
    srand(time(nullptr));
    Tower jfk;
    
    new Boeing(&jfk);
    new Airbus(&jfk);
    new Boeing(&jfk);
    new Airbus(&jfk);
    
    while(true){
        jfk.broadcast();
        jfk.observe();
        if(rand() % 2){
            if (rand() % 2)
                new Boeing(&jfk);
            else
                new Airbus(&jfk);
        }
    }
}

