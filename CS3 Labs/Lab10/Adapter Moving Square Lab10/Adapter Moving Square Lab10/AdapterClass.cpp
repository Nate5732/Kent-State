// Nathon Iadimarco
// Lab10 Adapter Moving Square
// figures: class adapter pattern
// Mikhail Nesterenko
// 11/7/2022

#include <iostream>

using std::cout; using std::endl;
using std::cin;

// target interface
class Square {
public:
    virtual void draw() const =0;
    virtual ~Square(){}
    virtual int size()=0;
    virtual void resize(int newSize){}
};

// adaptee/implementer
class LegacyRectangle{
public:
    LegacyRectangle(int topLeftX,
                    int topLeftY,
                    int bottomRightX,
                    int bottomRightY):
    topLeftX_(topLeftX),
    topLeftY_(topLeftY),
    bottomRightX_(bottomRightX),
    bottomRightY_(bottomRightY){}
    
    void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
        topLeftX_ = topLeftX;
        topLeftY_ = topLeftY;
        bottomRightX_ = bottomRightX;
        bottomRightY_ = bottomRightY;
    }
    
    // defining top/left and bottom/right coordinates
    int getTopLeftX() { return topLeftX_; }
    int getTopLeftY() { return topLeftY_; }
    int getbottomRightX() { return bottomRightX_; }
    int getbottomRightY() { return bottomRightY_; }
    
    void oldDraw() const {
        for(int i=0; i < bottomRightY_; ++i){
            for(int j=0; j < bottomRightX_; ++j)
                if(i >= topLeftY_  && j >= topLeftX_ )
                    cout << '*';
                else
                    cout << ' ';
            cout << endl;
        }
    }
    
private:
    int topLeftX_;
    int topLeftY_;
    int bottomRightX_;
    int bottomRightY_;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter: public Square,
private LegacyRectangle {
public:
    SquareAdapter(int size): LegacyRectangle(0,0,size,size){};
    void draw() const override {
        oldDraw();
    }
    
    int size() override {return getbottomRightX();}// returns square size which is equivalent to bottomright since its a square and all 4 sides are the same
    
    void resize(int newSize) override { this->move(0, 0, newSize, newSize); } // resizes square with new integer value given to resize by changing bottom x and y using move function.
};


int main(){
    int getSize;
    cout << "Provide original square size: ";
    cin >> getSize;
    cout << endl;
    Square *square = new SquareAdapter(getSize);
    square->draw();
    
    int getnewSize;
    cout << "Provide a new square size: ";
    cin >> getnewSize;
    square->resize(getnewSize);
    square->draw();
}
