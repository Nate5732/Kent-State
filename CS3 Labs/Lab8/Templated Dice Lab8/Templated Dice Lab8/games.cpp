// Nathon Iadimarco CS3
// Lab8 Templated Dice
// Implemented Dice Game

#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout; using std::endl;
using std::cin;

// template for any game where players take
// turns to make moves
// and there is a winner
class Game{
public:
    Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}
    
    // template method
    void playGame(const int playersCount = 0) {
        playersCount_ = playersCount;
        movesCount_=0;
        
        initializeGame();
        
        for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
            makeMove(i);
            if (i==playersCount_-1)
                ++movesCount_;
        }
        printWinner();
    }
    
    virtual ~Game(){}
    
protected:
    // primitive operations
    virtual void initializeGame() = 0;
    virtual void makeMove(int player) = 0;
    virtual void printWinner() = 0;
    virtual bool endOfGame() { return playerWon_ != noWinner;} // this is a hook
    // returns true if winner is decided
    static const int noWinner=-1;
    
    int playersCount_;
    int movesCount_;
    int playerWon_;
};


// Monopoly - a concrete game implementing primitive
// operations for the template method
class Monopoly: public Game {
public:
    // implementing concrete methods
    void initializeGame(){
        playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
    }
    
    void makeMove(int player) {
        if (movesCount_ > minMoves_){
            const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
            if (chance < movesCount_) playerWon_= player;
        }
    }
    
    void printWinner(){
        cout << "Monopoly, player "<< playerWon_<< " won in "
        << movesCount_<< " moves." << endl;
    }
    
private:
    static const int numPlayers_ = 8; // max number of players
    static const int minMoves_ = 20; // nobody wins before minMoves_
    static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing
// primitive operations
class Chess: public Game {
public:
    void initializeGame(){
        playersCount_ = numPlayers_; // initalize players
        for(int i=0; i < numPlayers_; ++i)
            experience_[i] = rand() % maxExperience_ + 1 ;
    }
    
    void makeMove(int player){
        if (movesCount_ > minMoves_){
            const int chance = (rand() % maxMoves_) / experience_[player];
            if (chance < movesCount_) playerWon_= player;
        }
    }
    
    void printWinner(){
        cout << "Chess, player " << playerWon_
        << " with experience " << experience_[playerWon_]
        << " won in "<< movesCount_ << " moves over"
        << " player with experience " << experience_[playerWon_== 0 ? 1:0]
        << endl;
    }
    
private:
    static const int numPlayers_ = 2;
    static const int minMoves_ = 2; // nobody wins before minMoves_
    static const int maxMoves_ = 100; // somebody wins before maxMoves_
    static const int maxExperience_ = 5; // player's experience
    // the higher, the greater probability of winning
    int experience_[numPlayers_];
};


// Dice Game
// Implemented by Nathon Iadimarco
class Dice: public Game {
public:
    void initializeGame(){
        playersCount_ = numPlayers_; // Initializing 2 players
    }
    
    void makeMove(int player) { // Rolling 5 dice
        if (movesCount_ > minMoves_) {
            
            // Computers turn
            if (player == 0) {
                cout << "Round " << movesCount_ - 1 << ": ";

                if (compAgain == 1 && movesCount_ != 2) { // If computer has not passed (0 is pass) and not on first move generate random num
                    compAgain = rand() % 2;// Making it 50/50 on if the computer will pass or not unless it has previously passed
                }
                if (compAgain == 0 && movesCount_ != 2) { // If random num generated 0 that means computer passed else if its 1, roll.
                    cout << "Computer rolled: passed";
                } else if (compAgain == 1) {
                    cout << "Computer rolled: ";
                    compSum = 0; // Initializing to 0 to get new value for new roll.
                    for (int i = 0; i < 5; ++i) { // Rolling dice 1-6 5 different times
                        const int compRoll = (rand() % 6) + 1;
                        cout << compRoll << " ";
                        compSum += compRoll; // Compound addition to add each roll value into a sum
                    }
                }
                cout << ", computer's score = " << compSum << endl;
            }
            
            
            // Players turn
            if (player == 1) {
                cout << "You rolled: ";
                if (rollAgain == 'n') {
                    cout << "passed";
                } else if (rollAgain != 'n') {
                    youSum = 0;
                    for (int i = 0; i < 5; ++i) { // Rolling dice 1-6 5 different times
                        const int youRoll = (rand() % 6) + 1;
                        cout << youRoll << " ";
                        youSum += youRoll; // Compound addition to add each roll value into a sum
                    }
                }
                cout << ", your score = " << youSum << endl;
                
                if (rollAgain == 'n' && compAgain == 0) { // If both players pass, there is a winner.
                    playerWon_ = player;
                } else if (movesCount_ == 4) { // If game goes past round 3, there is a winner.
                    playerWon_ = player;
                } else if (rollAgain != 'n') { // Otherwise, both conditions to end the game are not met, game asks for input from player to roll again.
                    cout << "Roll again? [y/n] ";
                    cin >> rollAgain;
                }
                
            }
        }
    }
    
    void printWinner(){
        if (youSum > compSum) cout << "You Win!" << endl;
        if (youSum == compSum) cout << "You Lose!" << endl;
        if (youSum < compSum) cout << "You Lose!" << endl;
    }
    
private:
    static const int numPlayers_ = 2; // max number of players
    static const int minMoves_ = 1; // nobody wins before minMoves_
    static const int maxMoves_ = 3; // somebody wins before maxMoves_
    char rollAgain; // Determines if player wants to roll again or not.
    int compAgain = 1; // Determines if computer wants to roll again or not.
    int youSum = 0; // Used to gather players sum of all 5 rolls for either current turn or turn that was passed
    int compSum = 0; // Used to gather the computers sum of all 5 rolls for this turn
    
};


int main() {
    srand(time(nullptr));
    
    Game* gp = nullptr;
    
    /*
     // play chess 7 times
     for (int i = 0; i < 7; ++i){
     gp = new Chess;
     gp->playGame();
     delete gp;
     }
     
     
     // play monopoly 7 times
     for (int i = 0; i < 7; ++i){
     gp = new Monopoly;
     gp->playGame();
     delete gp;
     }
     */
    
    // Plays Dice Game
    gp = new Dice;
    gp->playGame();
    delete gp;
    
}

