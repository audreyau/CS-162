# Lab 6: Applying Polymorphism
(7 pts for attendance, 3 points for completing the lab)
In this week’s lab we will build on the earlier work that we completed in Week 5. We aren’t going to
design new classes. Instead, we are going to modify our previous design and configure the ```area()```
function to use polymorphism.

Since a generic shape does not have a known area, change the area() member function (inside the
Shape class) to be purely virtual.
```
virtual float area() = 0;
```

Note that Shape has now become an abstract class. What does this mean?
Make sure that you can create objects of type ```Rectangle```, ```Circle```, and ```Square```, and that the area()
member function works correctly for each type of object.

In order to demonstrate polymorphism, we have another task:
- In your main() function write code to dynamically allocate an array of Shape variables (i.e.
allocate an array of pointers to shapes).
```Shape** array_of_shapes = new Shape*[3];```
- Next, dynamically allocate a Rectangle object, a Circle object, and a Square object. Ensure
that each shape has non-zero dimensions (e.g. the area of each shape is not 0).
- For each of these three objects, add a corresponding pointer into the array_of_shapes.
Write a ```for``` loop that iterates across each pointer inside array_of_shapes and displays the value
returned by the ```area()``` member function. If your program is properly designed to use polymorphism,
you will be able to see that the correct area is displayed (corresponding to the type of each object).

**Operator Overloads**
Make an operator overload member for comparing shapes based on their area. For example, you
want to have the ability to compare two shapes using the > and < operators, such as if (s1 > s2). In
order to do this, you need to make an operator overload for > or <.
Implement **one** of these two functions:
```
  bool operator>(const Shape &, const Shape &);
  bool operator<(const Shape &, const Shape &);
```

Inside your main() function, write example code that creates a circle and a square. Use your
overloaded comparison operator to compare the two shapes. For example, this approach could work:
```
Circle myCircle(3.2);
Square mySquare(1);
if (myCircle > mySquare) {
  cout << “the circle has a larger area”
}
```
