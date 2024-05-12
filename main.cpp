//--------------- main.cpp ---------------
//Gabrielle Vays

#include <iostream>
#include "shapes.h"
using namespace std;

void ShowMenu()
{
    cout << "\tWelcome to the Shape List!";
    cout << "\n\tE \tEnroll a shape";
    cout << "\n\tL \tList all the shapes ";
    cout << "\n\tA \tArea of all the shapes combined";
    cout << "\n \tP \tPerimeter of all the shapes combined";
    cout << "\n \tM \tSee the Menu";
    cout << "\n\tX \tExit ";
}

char GetAChar(const char* prompt)
// Prompt the user and get a single character,
// discarding the Return character.
// Used in GetCommand.
{
    char option;			// the char to be returned

    cout << prompt;		// Prompt the user
    cin >> option;			// Get a char,
    option = toupper(option);	// and convert it to uppercase
    cin.get();				// Discard newline char from input.
    return option;
}

bool Legal(char s)
// Determine if a particular character, c, corresponds
// to a legal menu command.  Returns true if legal, false if not.
// Used in GetCommand.
{
    return	((s == 'E') || (s == 'L') || (s == 'A') ||
               (s == 'P') || (s == 'M') || (s == 'X'));
}

char GetCommand() {
    char cmd = GetAChar("\n\n>");

    while (!Legal(cmd)) {
        cout << "\nIllegal command, please try again . . .";
        ShowMenu();
        cmd = GetAChar("\n\n>");
    }
    return cmd;
}

int main() {
    int capacity = 5;
    int size = 0;
    Shape** shapes = new Shape*[capacity];
    string shape_name;
    double total_area = 0;
    double total_Perim = 0;
    ShowMenu();				// Display the menu.
    char command;			// menu command entered by user
    do {
        command = GetCommand();        // Retrieve a command.
        switch (command) {
            case 'E':
                if(size == capacity)
                {
                    capacity = size + 5;			// Determine a new size.
                    Shape** new_shapes = new Shape*[capacity];		// Allocate a new array.
                    cout << "Array being resized to " << capacity << " allocated spots"<<endl;
                    for (int i = 0; i < size; i++)	// Copy each entry into
                    {
                        new_shapes[i] = shapes[i];        // the new array.
                    }
                    delete [] shapes;			// Remove the old array
                    shapes = new_shapes;			// Point old name to new array.
                }
                cout << "\nType the shape that you want to add (Square, Circle, Triangle), followed by RETURN or ENTER: ";
                getline(cin, shape_name);
                if(shape_name == "Square")
                {
                    double side;
                    cout << "Enter the side length\n";
                    cin >> side;
                    shapes[size] = new Square(side);
                    size++;
                }
                else if(shape_name == "Circle")
                {
                    double radius;
                    cout << "Enter the radius length\n";
                    cin >> radius;
                    shapes[size] = new Circle(radius);
                    size++;
                }
                else if(shape_name == "Triangle")
                {
                    double base, height, hypot;
                    cout << "Enter the base length\n";
                    cin >> base;
                    cout << "Enter the height length\n";
                    cin >> height;
                    cout << "Now, enter the length of the hypotenuse\n";
                    cin >> hypot;
                    shapes[size] = new Triangle(base, height, hypot);
                    size++;
                }
                else
                {
                    cout << "Invalid shape name entered." << endl;
                }

                break;
            case 'L':
                if(size > 0){
                    for(int i = 0; i < size; i++)
                    {
                        cout <<"Shape " << i + 1 <<": "<<endl;
                        cout<< typeid(*shapes[i]).name() + 1 << ": ";
                        cout << "\n\tArea: " << shapes[i]->GetArea()
                             << "\n\tPerimeter: " << shapes[i]->GetPerimeter()
                             << endl;
                    }
                }
                break;
            case 'A':
                cout << "The aggregated area for the array is: \n";
                if(size > 0){
                    for(int i = 0; i < size; i++)
                    {
                        total_area += shapes[i]->GetArea();
                    }
                }
                cout << total_area;
                break;
            case 'P':
                cout << "The aggregated perimeter for the array is: \n";
                if(size > 0){
                    for(int i = 0; i < size; i++)
                    {
                        total_Perim += shapes[i]->GetPerimeter();
                    }
                }
                cout << total_Perim;
                break;
            case 'M':
                ShowMenu();
                break;
            case 'X':
                break;
        }



}while(command != 'X');

    for (int i = 0; i < size; i++) {
        delete shapes[i]; // Delete each dynamically allocated shape object.
    }

    delete[] shapes;

    return 0;

 }