// Nathon Iadimarco
// Prototype Scheduler Lab10

#include <iostream>
#include <string>
#include <ctime>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;

class State;

//context
class Process {
public:
    Process();
    Process(State* state) :state_(state) {
        nextIdentifier++;
        id = nextIdentifier;
    }
    
    // Behaviors
    void create();
    void suspend();
    void exit();
    void dispatch();
    void unblock();
    void block();
    string report();
    
    int getId()const { return id; }
    Process* clone(){
        return new Process(state_);
    }
    
    // part of implementation of state pattern
    void changeState(State* state){state_=state;}
private:
    State* state_;
    static int nextIdentifier; // Static variable to keep track of the next available identifier
    int id;
};
int Process::nextIdentifier = 0;

//abstract state class
class State {
public:
    virtual void create(Process*) {}
    virtual void suspend(Process*) {}
    virtual void exit(Process*) {}
    virtual void dispatch(Process*) {}
    virtual void unblock(Process*) {}
    virtual void block(Process*) {}
    virtual string report() = 0;
    
    void changeState(Process* process, State* state) {
        process->changeState(state);
    }
};


// Ready state class
class Ready : public State {
public:
    static State* instance() {
        static State* instance_ = new Ready;
        return instance_;
    }
    void dispatch(Process* n)override;
    string report() override {
        return "READY";
    }
};


// Running state class
class Running :public State {
public:
    static State* instance() {
        static State* instance_ = new Running;
        return instance_;
    }
    void suspend(Process* n) override;
    void exit(Process* n) override;
    void block(Process* n)override;
    string report() override {
        return "RUNNING";
    }
};


// Blocked state class
class Blocked :public State {
public:
    static State* instance() {
        static State* instance_ = new Blocked;
        return instance_;
    }
    void unblock(Process* n)override;
    
    string report()override {
        return  "BLOCKED";
    }
};

// Exit state class
class Exit :public State {
public:
    static State* instance() {
        static State* instance_ = new Exit;
        return instance_;
    }
    string report()override {
        return "EXITED";
    }
};

// Process behaviors
void Process::create() { state_->create(this); }
void Process::dispatch() { state_->dispatch(this); }
void Process::suspend() { state_->suspend(this); }
void Process::exit() { state_->exit(this); }
void Process::block() { state_->block(this); }
void Process::unblock() { state_->unblock(this); }

//state transitions member functions
string Process::report() {
    return state_->report();
}

void Ready::dispatch(Process* P) {
    changeState(P, Running::instance());
}
void Running::exit(Process* P) {
    changeState(P, Exit::instance());
}
void Running::block(Process* P) {
    changeState(P, Blocked::instance());
}
void Running::suspend(Process* P) {
    changeState(P, Ready::instance());
}
void Blocked::unblock(Process* P) {
    changeState(P, Ready::instance());
}

Process::Process() {
    state_ = Ready::instance();
}

int main() {
    srand(time(nullptr));
    Process prototype;
    queue<Process*> readyQueue; // Ready Queue
    queue<Process*>blockedQueue; // Blocked Queue
    
    for (int i = 1;i < 5;++i) { // Generating the 4 PIDs
        readyQueue.push(prototype.clone());
        cout << "PID " << i << ": created" << endl;
        cout << "PID " << i << " state: " << readyQueue.front()->report() << endl;
    }
    cout << "---------- Scheduler Running ----------" << endl;
    
    while (!readyQueue.empty() || !blockedQueue.empty()) { // While ready queue is not empty or blocked queue is not empty
        
        
        int unblockChance = rand() % 2 ; // 50/50 chance of being unblocked
        if (readyQueue.empty()) {
            cout << "The ready queue is empty" << endl;
            cout << endl;
            unblockChance = 0; // Force unblocking the blocked PID in blocked queue if the ready queue is empty
        }
        if (!blockedQueue.empty() && unblockChance == 0) { // If blocked queue is not empty and 50/50 success
            blockedQueue.front()->unblock(); // Unblocks PID
            readyQueue.push(blockedQueue.front()); // Pushing PID back into READY queue.
            cout << "Unblocking..." << endl;
            cout << "PID " << blockedQueue.front()->getId() << " state: " << readyQueue.front()->report() << endl;
            cout << endl;
            blockedQueue.pop();
        }
    
        if (!readyQueue.empty()) {
            cout << "Dispatching... " << endl;
            readyQueue.front()->dispatch();
            cout << "PID " << readyQueue.front()->getId() << " state: RUNNING" << endl;
            int stateChance = rand() % 3; // 33% chance for each state to happen
            switch (stateChance) { // Switch statement to run case number that got chosen
                case 0:
                    readyQueue.front()->block();
                    blockedQueue.push(readyQueue.front());
                    cout << "Blocking..." << endl;
                    cout << "PID " << readyQueue.front()->getId() << " state: BLOCKED" << endl;
                    cout << endl;
                    readyQueue.pop();
                    break;
                case 1:
                    readyQueue.front()->exit();
                    cout << "Exiting..." << endl;
                    cout << "PID " << readyQueue.front()->getId() << " state: EXITED" << endl;
                    cout << endl;
                    readyQueue.pop();
                    break;
                case 2:
                    readyQueue.front()->suspend();
                    cout << "Dispatching... " << endl;
                    cout << "PID " << readyQueue.front()->getId() << " state: RUNNING" << endl;
                    cout << endl;
                    readyQueue.push(readyQueue.front());
                    readyQueue.pop();
                    break;
            }
        }
    }
    cout << "all processes exited." << endl;
    cout << "---------- Scheduler Done ----------" << endl;
}
