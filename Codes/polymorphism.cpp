/**
 * The assignment's objective is to encode polymorphism. This assignment involves
 * classes, inheritance, pointers, and polymorphism.
 * 
 * Polymorphism (dynamic binding) is introduced, which is the ability of objects of 
 * different classes related by inheritance to respond differently to the same member 
 * function call. Polymorphism is made possible through class inheritance from a base 
 * class or from a derived class, overriding member functions, virtual member functions,
 * pointers, and dynamic binding.
 * 
 * Abstract classes are introduced, which is a base class that cannot instantiate
 * objects but can be declared by the use of pointers. Virtual functions of an abstract class
 * does not have a function body, but sets the function prototype to 0, this is called "pure" 
 * virtual functions.
 * Ex: virtual char * name() = 0;
 * 
 * Concrete classes are introduced, classes that can instantiate object. In this case, the derived
 * classes are concrete classes.
 * 
 * Since this assignment revolves around an array of pointers that is of type Shape (the abstract
 * class) pointing at the derived classes (the elements in the array), virtual member functions and
 * pointers are used to make polymorphism to happen - to use the (object's) function version that
 * is of that derived class. This is dynamic binding.
 * Ex:  Point3D point(3,4,5);
 *      Point2D *pointer2D = &point;
 *      // should return the value of point(3,4,5) as if it was called for output.
 *      cout << pointer2D;
 * If the member functions are not virtual and pointers were used, the pointer's class function
 * will be called rather than the function of the class that it is pointing to and vise versa.
 * This is static binding.
 * Virtual member functions are like overridden functions - same name, parameters, but 
 * in different classes and has different codes. The difference between this and a regular overriden function
 * is that if an object of type base class is pointing to the address of an object of type derived class,
 * it will call that class' function (much like the example above). Virtual member functions are implemented in 
 * base classes and derived classes that requires that certain method of returning a value, 
 * 
 * Only using protected to classes that are going to be inherited, otherwise private.
 * 
 * Class hierarchy:
 *                     Shape
 *                   /   |   \
 *                  /  Square \
 *                 /     |     \
 *                /     Cube  Triangle
 *             Circle            \
 *             /    \        Tetrahedron
 *            /      \
 *        Sphere   Cylinder
 * 
 * This program takes user input.
 * 
 * @author      Meyer, Edward (Provided the abstract class, Circle derived class, and main())
 * @author      Tuzon, Waltz Axl C. (Implemented the rest of the derived classes)
 * @assignment  ICS 212 Assignment 24
 * @date        December 5, 2023
 */

#include <iostream>
// Including cmath library to use sqrt() function.
#include <cmath>

#define NUM 7
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
    virtual double volume() const{
      return 0;
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
    
    virtual const char* name() const {
      return "Circle";
    }
  
    virtual void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
    } 
    
    virtual void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
    }
    
    virtual double area() const {
      return MY_PI * radius * radius;
    }
   
  protected:    
    double radius;
};

class Sphere: public Circle{

public:

  Sphere(double radiusParam = 1): Circle(radiusParam){

  }

  virtual const char* name() const {

      return "Sphere";

    }
  
  virtual void printDetails() const {

    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;

  } 

  virtual double area() const{

    return (4 * MY_PI * (radius * radius));

  }

  virtual double volume() const{

    return ((4 * MY_PI * (radius * radius * radius)) / 3);

  }

};

class Cylinder: public Circle{

public:

  Cylinder(double radiusParam = 1, double heightParam = 1): Circle(radiusParam){

    height = heightParam;
    
  }

  virtual const char* name() const {

      return "Cylinder";

    }
  
  virtual void printDetails() const {

    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;

  } 

  virtual void inputData() {

      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
      cout << "Enter the " << name() << "'s height: ";
      cin >> height;

    }

  virtual double area() const{

    return ((2 * MY_PI * radius * height) + (2 * MY_PI * (radius * radius)));

  }

  virtual double volume() const{

    return (MY_PI * (radius * radius) * height);

  }  

private:

  double height;

};

class Square: public Shape{

public: 

  Square(double sideParam = 1){

    side = sideParam;

  }

  virtual const char* name() const {
      return "Square";
    }
  
  virtual void printDetails() const {

    cout << "The " << name() << "'s area = " << area() << endl;

  } 

  virtual void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> side;

    }

  virtual double area() const{

    return (side * side);

  }

protected:

  double side;

};

class Cube: public Square{

public:

  Cube(double sideParam = 1): Square(sideParam){

  }

  virtual const char* name() const {
      return "Cube";
    }
  
  virtual void printDetails() const {

    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;

  } 

  virtual double area() const{

    return (6 * (side * side));

  }

  virtual double volume() const{

    return (side * side * side);

  }  

};

class Triangle: public Shape{

public:

  Triangle(double sideParam = 1){

    side = sideParam;
  
  }

  virtual const char* name() const {
    return "Triangle";
  }

  virtual void printDetails() const {

    cout << "The " << name() << "'s area = " << area() << endl;

  } 

  virtual void inputData() {
      cout << "Enter the " << name() << "'s side: ";
      cin >> side;

    }

  virtual double area() const{

    return ((side * side) * (sqrt(3) / 4));

  }

protected:

  double side;

};

class Tetrahedron: public Triangle{

public:

  Tetrahedron(double sideParam = 1): Triangle(sideParam){

  }

  virtual const char* name() const {
      return "Tetrahedron";
    }

    virtual void printDetails() const {

      cout << "The " << name() << "'s surface area = " << area() << endl;
      cout << "The " << name() << "'s volume = " << volume() << endl;

    } 

    virtual double area() const{

      return ((side * side) * sqrt(3));

    }

    virtual double volume() const{

      return ((side * side * side) * (sqrt(2) / 12));

    }

};

/** Add the remaining classes here. */

int displayMenu(Shape *[]);

int main() {
   
  Shape *shapeArray[NUM];
  shapeArray[0] = new Circle();

 // Uncomment the line below when you have completed its corresponding classs for that shape.
 // The shape will be added to the array and the corresponding menu option will be shown.
  shapeArray[1] = new Sphere();
  shapeArray[2] = new Cylinder();
  shapeArray[3] = new Square();
  shapeArray[4] = new Cube();
  shapeArray[5] = new Triangle();
  shapeArray[6] = new Tetrahedron();

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
