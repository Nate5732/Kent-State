// Nathon Iadimarco
// Lab13 Registry
// Edited Observer to use key lookups instead of pointers
// Observers may subscribe to and unsubscribe from messages in subjects by the subject's names rather than pointers.

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout; using std::endl;
using std::map; using std::set;
using std::string;

class Observer;
class Subject;

class EventRegistry {
public:
    static void registerObserver(string , Observer*);
    static void deregisterObserver(string , Observer*);
    static void handleMessage(Subject* );
private:
    static map<string, set<Observer*>> observerMap_;
};

// initialize the static map
map<string, set<Observer*>> EventRegistry::observerMap_;


class Observer{
public:
    Observer(const string& name) : name_(name) {}
    string getName() const { return name_; }
    void subscribe(string s) { EventRegistry::registerObserver(s, this); }
    void unsubscribe(string s) { EventRegistry::deregisterObserver(s, this); }
    void handleMessage(Subject *s );
private:
    string name_;
};

class Subject {
public:
    Subject(const string& name) : name_(name) {}
    string getName() const { return name_; }
    void generateMessage() {
        cout << name_ << " sent a message" << endl;
        EventRegistry::handleMessage(this);
    }
private:
    string name_;
};

void EventRegistry::registerObserver(string s, Observer* o) {
    observerMap_[s].insert(o);
    cout << o->getName() << " subscribed to "<< s << endl;
}

void EventRegistry::deregisterObserver(string s, Observer* o) {
    observerMap_[s].erase(o);
    cout << o->getName() << " unsubscribed from " << s << endl;
}

void EventRegistry::handleMessage(Subject* s) {
    for (auto e : observerMap_[s->getName()])
        e->handleMessage(s);
}

void Observer::handleMessage(Subject* s) {
    cout << name_ << " received message from "<<s->getName()<<endl;
}


int main() {
        Subject  sue("Subject Sue"), steve("Subject Steve");
        Observer olaf("Observer Olaf"), olga("Observer Olga");

        olaf.subscribe(sue.getName()); olaf.subscribe(steve.getName());
        olga.subscribe(sue.getName());

        cout << endl;


        sue.generateMessage();
        steve.generateMessage();
        cout << endl;

        olga.unsubscribe(sue.getName());
        sue.generateMessage();

    }
   

