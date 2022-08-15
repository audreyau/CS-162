# Lab 5: Implementing Inheritance
(7 pts for attendance, 3 points for completing the lab)
This lab will provide you with additional programming practice. We’re going to work with
shapes in this lab exercise. We’ll create several classes to represent different shapes,
some of them using inheritance.

**Implement a generic ***Shape*** class** <br/>
The first class we’ll write is one to represent a generic shape with a name and a color.

Create two new files, ```shape.h``` and ```shape.cpp```, and in them, define a ```Shape``` class.
Here’s the start of a class definition you should use:
```
class Shape {
  private:
  string name;
  string color;
public:
  float area();
  ...
};
```

You class should also have constructors, accessors, and mutators, as appropriate. In
addition, your class should have an ```area()``` member function for computing the shape’s
area. For this generic ```Shape``` class, the ```area()``` member function can simply return 0,
since we don’t know how to compute the area of an unknown shape.

In addition to your files ```shape.h``` and ```shape.cpp```, create a new file
```application.cpp```. In this file, write a simple main() function that instantiates some
Shape objects and prints out their information. Ensure that you have a ```Makefile``` to
compile all parts of your program. I suggest that you use the [Advanced Makefile](https://web.engr.oregonstate.edu/~goinsj/resources/general/C++/Makefile)
available on Canvas. It’s the same file that we’ve previously used in class demos.

**Implement ***Rectangle*** and ***Circle*** class**
Create new files ```rectangle.h```, ```rectangle.cpp```, ```circle.h```, and ```circle.cpp```, and
in them, implement a Rectangle class and a Circle class. Both of these classes
should be derived from your ```Shape``` class. The Rectangle class should have a width
and a ```height```, and the ```Circle``` class should have a ```radius```. Here are the beginnings
of definitions for these classes:

```
class Rectangle : public Shape {
private:
  float width;
  float height;
public:
  float area();
  ...
};

class Circle : public Shape {
private:
  float radius;
public:
  float area();
  ...
};
```
Both of these classes should have constructors, accessors, and mutators, as needed.
Both classes also need to redefine (i.e. override) the ```Shape``` class’s ```area()``` member
function to compute areas that are appropriate for rectangles and circles.

Add some code to your application to instantiate and print out some ```Rectangle``` and
```Circle``` objects. Be sure that you display the computed area.

**Implement a ***Square*** class**
Now, create new files ```square.h``` and ```square.cpp```, and in them, implement a ```Square```
class that derives from your ```Rectangle``` class. Your ```Square``` class should not contain
any new data members, nor may you change any members of the ```Rectangle``` class to
```protected``` or ```public``` access. Instead, you should figure out how to implement a
public interface for your ```Square``` class by appropriately using the ```width``` and ```height``` of
your ```Rectangle``` class ***via its public interface*** (i.e. via the ```Rectangle``` class’s
constructors, accessors, and mutators). Specifically, the public interface to your
```Square``` class should use the public interface of your ```Rectangle``` class while enforcing
the constraint that a square’s width and height are equal.

Here’s a definition for your Square class, with no new data members:
```
class Square : public Rectangle {
public:
  // constructor to set inherited width and height values
  Square(double len);
};
```

Once your ```Square``` class is written, add some lines to your application to instantiate and
print out some ```Square``` objects (be sure to print the area).
