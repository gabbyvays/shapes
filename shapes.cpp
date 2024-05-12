//--------------- shapes.cpp ---------------
//Gabrielle Vays

#include <iostream>
#include "shapes.h"

using namespace std;

Square::Square()
{
    side = 0;
}

Square::Square(double s)
{
    side = s;
}

double Square::GetPerimeter()
{
    double Perim;
    Perim = 4 * side;

    return Perim;
}

double Square::GetArea()
{
    double Area;
    Area = side * side;

    return Area;
}

Circle::Circle()
{
    radius = 0;
}

Circle::Circle(double r)
{
    radius = r;
}

double Circle::GetPerimeter()
{
    double Perim;
    Perim = (2 * 3.14 * radius);

    return Perim;
}

double Circle::GetArea()
{
    double Area;
    Area = (3.14 * radius * radius);

    return Area;
}

Triangle::Triangle()
{
    base = 0;
    height = 0;
    hypotenuse = 0;
}

Triangle::Triangle(double b, double ht, double hyp)
{
    base = b;
    height = ht;
    hypotenuse = hyp;
}

double Triangle::GetPerimeter()
{
    double Perim;
    Perim = base + height + hypotenuse;

    return Perim;
}

double Triangle::GetArea()
{
    double Area;
    Area = (base * height)/2;

    return Area;
}