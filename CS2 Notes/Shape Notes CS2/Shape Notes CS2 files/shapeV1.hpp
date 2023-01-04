



// Nathon Iadimarco
//
#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <iostream>


class shape {
public:
    shape(int nx=0, int ny=0) : x(nx), y(ny) {};
    virtual ~shape() {};
    void move(int nx, int ny) { x = nx; y = ny; };
    virtual void draw() const = 0; //Pure virtual
    virtual bool isCircle() const = 0;
    virtual bool isTriangle() const = 0;
    virtual bool isRectangle() const = 0;
    virtual bool isSquare() const = 0;
    
protected:
    int x, y;
};

class circle : public shape {
public:
    circle(int radius=0) : shape(), r(radius) {};
    void draw() const { std::cout << "Circle at: " << x << ", " << y
                                  << " with radius " << r << std::endl; };
    virtual bool isCircle() const { return true; };
    virtual bool isTriangle() const { return false; };
    virtual bool isRectangle() const { return false; };
    virtual bool isSquare() const { return false; };
protected:
    int r;
};

class triangle : public shape {
public:
    triangle(int nb=0, int nh=0) : shape(), b(nb), h(nh) {};
    void draw() const { std::cout << "Triangle at: " << x << ", " << y
                                  << " with base, height " << b << ", " << h << std::endl; };
    virtual bool isCircle() const { return false; };
    virtual bool isTriangle() const { return true; };
    virtual bool isRectangle() const { return false; };
    virtual bool isSquare() const { return false; };
protected:
    int b, h;
};

class rectangle : public shape {
public:
    rectangle(int nh=0, int nw=0) : shape(), h(nh), w(nw) {};
    void draw() const { std::cout << "Rectangle at: " << x << ", " << y
        << " with height, width " << w << ", " << h << std::endl; };
    virtual bool isCircle() const { return false; };
    virtual bool isTriangle() const { return false; };
    virtual bool isRectangle() const { return true; };
    virtual bool isSquare() const { return false; };
protected:
    int h, w;
};

class square : public rectangle {
public:
    square(int nh=0) : rectangle(nh, nh)  {};
    void draw() const { std::cout << "Square at: " << x << ", " << y
        << " with height, width " << w << ", " << h << std::endl; };
    virtual bool isCircle() const { return false; };
    virtual bool isTriangle() const { return false; };
    virtual bool isRectangle() const { return true; };
    virtual bool isSquare() const { return true; };
};

#endif
