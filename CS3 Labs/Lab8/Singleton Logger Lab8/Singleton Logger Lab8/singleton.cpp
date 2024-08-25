// Nathon Iadimarco
// Lab8 Singleton Logger
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using std::cout; using std::endl;

class Logger{
public:
    
    // returns pointer to single instance
    static Logger* instance();
    
    // example functions manipulating singleton object
    int getI() const {return i_;}
    void setI(int i) {i_=i;}
    void report(const std::string&);
    
    
private:
    // initialization is prohibited
    Logger(){} // private so that it cannot be invoked
    
    // copying prohibited
    // Singleton(const Singleton&){}
    // Singleton& operator=(const Singleton&){}
    
    // pointer to its instance
    static Logger* onlyInstanceInt_;
    
    int i_; // payload
    std::ofstream fout;
};



Logger* Logger::onlyInstanceInt_ = nullptr;

// returns pointer to instance of singleton
Logger* Logger::instance(){
    if(onlyInstanceInt_ == nullptr) {
        onlyInstanceInt_ = new Logger;
    onlyInstanceInt_->fout.open("log.txt", std::fstream::out | std::fstream::app);
    }
    return onlyInstanceInt_;
}

void Logger::report(const std::string& text) {
    fout << text << endl;
}

void func1() {
    Logger::instance() -> report("Hi from func1");
}

void func2() {
    Logger::instance() -> report("Hi from func2");
}

void exiting() {
    std::ofstream fout;
    if (fout.is_open()) {
        fout.close();
    }
}

// demonstration of singleton usage
int main(){
    
    // calling both functions
    func1();
    func2();
    atexit(exiting);
}
