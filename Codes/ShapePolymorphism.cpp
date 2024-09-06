#include <iostream>
#include <cmath>

/**
 * Program header goes here.
 */

#define NUM 1
#define MY_PI 3.14

using namespace std;

class Shape {
  public:
    /** Returns the name of the class. */
    virtual const char* name() const = 0;
    /** Prints the area or surface area, and volume of the object. */
    virtual void printDetails() const = 0;
    /**
     * Prompts the user to enter a radius, side, and/or height
     * of the object and set the appropriate data member(s).
     */
    virtual void inputData() = 0;
    /** Calculates and returns the area or surface area of the object. */
    virtual double area() const = 0;
    /** Calculates and returns the volume of the object. */
    virtual double volume() const {
      return 0.0;
    }     
};   

class Circle : public Shape {
  public:
    // Parameter syntax "datatype variable = value" will give
    // a default value for the variable if one is not supplied as an argument.
    // This constructor can be called with no arguments or one argument
    // Example: shapeArray[0] = new Circle(); 
    // Example: Circle circle1 = new Circle(10);
    Circle (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Circle";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
    }
    
    double area() const {
      return MY_PI * radius * radius;
    }
   
  protected:    
    double radius;
};


/** Add the remaining classes here. */

int displayMenu(Shape *[]);

int main() {
   
  Shape *shapeArray[NUM];
  shapeArray[0] = new Circle();

 // Uncomment the line below when you have completed its corresponding classs for that shape.
 // The shape will be added to the array and the corresponding menu option will be shown.
 // shapeArray[1] = new Sphere();
 // shapeArray[2] = new Cylinder();
 // shapeArray[3] = new Square();
 // shapeArray[4] = new Cube();
 // shapeArray[5] = new Triangle();
 // shapeArray[6] = new Tetrahedron();

  int choice = displayMenu(shapeArray);
  while (choice >= 0 && choice <= 6) {
    shapeArray[choice]->inputData();
    shapeArray[choice]->printDetails();
    cout << endl;
    choice = displayMenu(shapeArray);
  }
  return 0;
}

/**
 * Displays the menu for which shape to perform calculations.
 *
 * @param shapeArrayParam array of shapes that this program supports
 * @return the choice from the user
 */
int displayMenu(Shape *shapeArrayParam[]) {
  int choice = 0;
  cout << "Select an object from the menu (enter 7 to quit)." << endl;
  for (int i = 0; i < NUM; i++) {
    cout << '\t' << i << ". " << shapeArrayParam[i]->name() << endl;
  }
  cin >> choice;
  return choice;
}

/*
Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
0
Enter the Circle's radius: 10
The Circle's area = 314

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
1
Enter the Sphere's radius: 20
The Sphere's surface area = 5024
The Sphere's volume = 33493.3

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
2
Enter the Cylinder's radius: 30
Enter the Cylinder's height: 40
The Cylinder's surface area = 13188
The Cylinder's volume = 113040

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
3
Enter the Square's side: 50
The Square's area = 2500

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
4
Enter the Cube's side: 60
The Cube's surface area = 21600
The Cube's volume = 216000

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
5
Enter the Triangle's side: 70
The Triangle's area = 2121.76

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
6
Enter the Tetrahedron's side: 80
The Tetrahedron's surface area = 11085.1
The Tetrahedron's volume = 60339.8

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
7
*/
