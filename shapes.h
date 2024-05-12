//--------------- shapes.h ---------------
//Gabrielle Vays

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double GetPerimeter() = 0;
    virtual double GetArea() = 0;

protected:

};

class Square: public Shape
{
public:
    Square();
    Square(double s);

    double GetPerimeter();
    double GetArea();
private:
    double side;
};

class Circle: public Shape
{
public:
    Circle();
    Circle(double r);
    double GetPerimeter();
    double GetArea();
private:
    double radius;

};

class Triangle: public Shape
{
public:
    Triangle();
    Triangle(double b, double ht, double hyp);
    double GetPerimeter();
    double GetArea();
private:
    double base;
    double height;
    double hypotenuse;
};
