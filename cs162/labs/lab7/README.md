# Lab 7: Using C++ Template Classes
(7 pts for attendance, 3 points for completing the lab)

The C++ STL (Standard Template Library) includes many classes that are intended to make your life
easier. One of these is the **vector** which is essentially a dynamically allocated array. A vector stores
items on the heap but it automatically takes care of all the memory management for you. You don’t
have to worry about **new**, **delete**, expanding the array, etc.

cplusplus.com is the de facto reference for any questions that you may have about the STL classes.
This page should be useful for the lab: https://cplusplus.com/reference/vector/vector/

Vectors can store items of essentially any type (including custom objects). In order to demonstrate
their versatility, we will utilize the Meerkat class that you created in your earlier homework
assignment. Since Meerkat inherits from Animal, be sure to copy both classes (the .cpp and .h files)
into a new lab7 directory. Feel free to ask a lab partner for their version of the files if you prefer.

Modify your Animal class to contain a protected “name” member variable of type string. Write a
Meerkat constructor that accepts a string and assigns it as the new meerkat’s name. Lastly, write a
new function in the animal class that will display the creature’s name: ```void displayName();```

If everything works, you should be able to correctly execute this code:
```
Meerkat mk1(“Emma”);
Meerkat mk2(“Liam”);
Meerkat mk3(“Oliver”);
mk2.displayName(); // this will print “Liam” on the console.
```

We are almost ready to create a vector of Meerkat objects. First we need to include the correct
header: ```#include <vector>```

Create a vector that can store meerkats: ```vector<Meerkat> den;```

Complete the following steps:
- Write code that adds Emma, Liam, and Oliver to the **den** vector.
- Print the number of items contained in the vector. You can do this using the size() function.
- Use the **front()** function to access the first Meerkat and print its name.
- Create a new meerkat with your choice of name. Use **push_back()** to add it into the vector.
- Use the **[ ]** (square brackets) operator to display the name of the meerkat at index 2.
- Use the **at()** function to display the name of the meerkat at index 2.
- 
Did you get the same answer from the last two steps? Read the online documentation to identify the
key difference between **at()** and **[ ]**. Be sure that you can explain your answer to the TA/instructor (at reports if it goes out of bounds, [] does not).

A traditional array can’t be copied using the = operator. Fortunately, the vector class implements an
assignment operator overload that enables this behavior. Create another vector named betterDen.
You can then use the = operator to copy the original den: ```betterDen = den;```

Lastly, write a **for** loop that prints the name of each meerkat in betterDen.
