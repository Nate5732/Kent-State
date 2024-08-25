// Nathon Iadimarco
// State Transitions Lab10

#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

class State;

//context
class Process {
public:
    Process();
    // Behaviors
    void create();
    void suspend();
    void exit();
    void dispatch();
    void unblock();
    void block();
    string report();
    
    // part of implementation of state pattern
    void changeState(State* state){state_=state;}
private:
    State* state_;
    static int nextIdentifier; // Static variable to keep track of the next available identifier
    int id;
};
int Process::nextIdentifier = 1; // First process gets id of 1

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
    cout << "Process " << id << " " << state_->report() << endl; // Reports process id and current state
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
    id = nextIdentifier;
    ++nextIdentifier; // Incrementing identifier once new process is created
    state_ = Ready::instance(); // Ensuring process is in ready state when created
}

int main() {
    // Testing process state transitions
    Process p1;
    p1.create(); // Sets to READY
    p1.report();

    p1.dispatch(); // Sets to RUNNING
    p1.report();

    p1.dispatch(); // Shows nothing happens when dispatch invoked on running process
    p1.report();

    p1.block(); // Sets to BLOCKED
    p1.report();

    p1.unblock(); // Sets back to READY (unblocks)
    p1.report();
    
    p1.dispatch(); // Sets to RUNNING
    p1.report();
    
    p1.suspend(); // Sets back to READY
    p1.report();
    
    p1.dispatch(); // Sets to RUNNING
    p1.report();
    
    p1.exit(); // Sets to EXITED (exited running process)
    p1.report();
    
}
