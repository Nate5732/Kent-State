// Nathon Iadimarco
// Lab12
// Checkpointed History
// implements command history (multiple undos)
// demonstrates command pattern


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector; using std::string; using std::stack;
using std::cout; using std::cin; using std::endl;

// receiver
class Document {
public:
    
    Document(const vector <string> & lines={}): lines_(lines){}
    
    // actions
    void insert(int line, const string &str) {
        const int index = line-1;
        if (index <= lines_.size())
            lines_.insert(lines_.begin() + index, str);
        else
            cout << "line out of range" << endl;
    }
    
    const string remove(int line) {
        const int index = line-1;
        string deletedLine="";
        if(index < lines_.size()){
            // deletedLine = lines_[index];
            deletedLine = *(lines_.begin()+index); // same thing but with iterator arithmetic
            lines_.erase(lines_.begin() + index);
        }else
            cout << "line out of range" << endl;
        return deletedLine;
    }
    
    void show() {
        for(int i = 0; i < lines_.size(); ++i)
            cout << i + 1 << ". " << lines_[i] << endl;
    }
    
private:
    vector<string> lines_;
};

// abstract command
class Command{
public:
    Command(Document *doc) : doc_(doc){}
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    virtual ~Command(){}
    virtual void show() = 0;
protected:
    Document *doc_;
};

// two concrete commands
class InsertCommand : public Command {
public:
    InsertCommand(Document *doc, int line, const string &str):
    Command(doc), line_(line),  str_(str) {}
    void execute() override {doc_->insert(line_, str_);}
    void unexecute() override {doc_->remove(line_);}
    void show() override {cout << "inserted '" << str_ << "' at line " << line_ << endl;}
private:
    int line_;
    string str_;
};


class EraseCommand : public Command {
public:
    EraseCommand(Document *doc, int line):
    Command(doc), line_(line), str_("") {}
    void execute() override {str_ = doc_->remove(line_);}
    void unexecute() override {doc_->insert(line_, str_);}
    void show() override {cout << "erased line " << line_ << endl;}
private:
    int line_;
    string str_;
};

// client
class DocumentWithHistory{
public:
    DocumentWithHistory(const vector<string> & text={}) : doc_(text){}
    
    void insert(int line, string str) {
        Command *com = new InsertCommand(&doc_, line, str);
        com->execute();
        doneCommands_.push(com);
    }
    
    void erase(int line){
        Command *com = new EraseCommand(&doc_, line);
        com->execute();
        doneCommands_.push(com);
    }
    
    void undo() {
        if(doneCommands_.size() != 0) {
            Command *com = doneCommands_.top();
            doneCommands_.pop();
            com->unexecute();
            delete com; // don't forget to delete command
        }else
            cout << "no commands to undo" << endl;
    }
    
    void show() {doc_.show();}
    
    void history() {
        cout << "History:" << endl;
        stack<Command*> temp;
        int commandNum = 1;
        while (!doneCommands_.empty()) {
            Command* currentCommand = doneCommands_.top(); // Getting command from top of stack
            doneCommands_.pop(); // Popping top command off stack
            cout << commandNum << " ";
            currentCommand->show();
            temp.push(currentCommand); // Push current command onto temp stack
            ++commandNum; // Iterating through each command number
        }
        while (!temp.empty()) {
            Command* currentCommand = temp.top();
            temp.pop();
            doneCommands_.push(currentCommand);

        }
    }
    
    void redo(int command) {
        stack<Command *> temp;
        Command *c; // Keeps track of current command

        if(doneCommands_.empty() || command > doneCommands_.size()) {
            cout << "No command history possible to redo." << endl;
        } else {
            for(int i = 0; i < command; ++i) {
                c = doneCommands_.top();
                doneCommands_.pop();
                temp.push(c);
            }
            
            c->execute();

            for (int i = 0; i < command - 1; ++i) {
                doneCommands_.push(temp.top());
                temp.pop();
            }
            doneCommands_.push(c);
        }
    }
    class Memento *createMemento();
    void rollBack(class Memento *);
private:
    Document doc_;
    std::stack<Command*> doneCommands_;
};

// Memento Class
class Memento {
public:
    Memento(const DocumentWithHistory& doc): doc_(doc) {}
    const DocumentWithHistory& getState() const {return doc_;}
private:
    const DocumentWithHistory doc_;
};

Memento *DocumentWithHistory::createMemento() {
    while(!doneCommands_.empty())
        doneCommands_.pop();
    return new Memento(*this); // copying the Document itself
}

void DocumentWithHistory::rollBack(Memento *mem){
    *this = mem->getState();  // copying back
}

// invoker
int main() {
    DocumentWithHistory his({
        "Lorem Ipsum is simply dummy text of the printing and typesetting",
        "industry. Lorem Ipsum has been the industry's standard dummy text",
        "ever since the 1500s, when an unknown printer took a galley of",
        "type and scrambled it to make a type specimen book. It has",
        "survived five centuries."});
    
    char option;
    do{
        static Memento *checkpoint = nullptr;
        cout << endl;
        his.show();
        cout << endl;
        
        cout << "Enter option (i)nsert line (e)rase line (u)undo last command (c)heckpoint roll(b)ack (h)history (r)edo command: ";
        cin >> option;
        
        int line; string str;
        switch(option) {
            case 'i':
                cout << "line number to insert: ";
                cin >> line;
                cout << "line to insert: ";
                cin.get(); // removes end-of-line character so getline() works correctly
                getline(cin, str);
                his.insert(line, str);
                break;
                
            case 'e':
                cout << "line number to remove: ";
                cin >> line;
                his.erase(line);
                break;
            case 'u':
                his.undo();
                break;
            case 'c':
                checkpoint = his.createMemento();
                break;
            case 'b':
                if (checkpoint != nullptr) {
                    his.rollBack(checkpoint);
                    delete checkpoint;
                    checkpoint = nullptr;
                }
                break;
            case 'h':
                his.history();
                break;
            case 'r':
                int input;
                cout << "Input command number to redo: ";
                cin >> input;
                his.redo(input);
                break;
        }
        
    } while (option == 'i' || option == 'e' || option == 'u' || option == 'c' || option == 'b' || option == 'h' || option == 'r');
}
