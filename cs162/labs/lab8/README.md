# Lab 8: An introduction to runtime complexity
This lab will illustrate the effects of software design choices.

For example purposes, we are going to create objects of type Meerkat and store them
into a [forward_list](http://www.cplusplus.com/reference/forward_list/forward_list/) which is a container from the STL (standard template library). We will
then perform some operations and compare the difference in execution time.

Since this is the final lab, you will automatically receive all 10 points if you attend class.


This lab assumes that you reuse your Meerkat class from last week. If you prefer to use
your Rectangle class, that’s fine too (just replace all mentions of *Meerkat* with
*Rectangle*).

Like last time, we will be constructing objects and assigning them a name.
```
// for example...
Meerkat mk5(“Leo”);
```

**Storing Meerkats into the container (Approach #1)**
First we need to create a forward_list to hold the meerkats. We will then push a user
specified number of items into the front of the forward_list.

We will use the chrono library to time the operation and see how long it takes the
computer to finish. Note: you will need to have C++11 support enabled (which is already
included if you use the same Makefile that I’ve previously distributed).

Here is some starter code to place into your driver (main.cpp) file:
```
// include the necessary libraries
#include <iostream>
#include <forward_list>
#include <chrono>
#include "animal.h"
#include "meerkat.h"

using namespace std;
using namespace std::chrono;

int main () {
 forward_list<Meerkat> list1;
 
 // get a user specified value
 cout << "How many meerkats do you want to store?" << endl;
 unsigned long int num;
 cin >> num;
 
 // fill the list with a bunch of objects
 auto start = high_resolution_clock::now();
 for (unsigned long int i = 0; i < num; i++) {
   Meerkat tmp("Anonymous Meerkat");
   list1.push_front(tmp); // this will copy the Meerkat into the list
 }
 auto stop = high_resolution_clock::now();
 
 // compute the elapsed time in microseconds
 auto duration = duration_cast<microseconds>(stop - start);
 cout << "Duration (us) for part 1: " << duration.count() << endl;

 // now write code which will insert num Meerkats into list2.
 // the difference is that this code needs to insert each Meerkat
 // at the END of the forward_list
 
 forward_list<Meerkat> list2;
 
 // put your code here...
 return 0;
}
```

**Storing Meerkats at the end of the container (Approach #2)**
Use [insert_after()](http://www.cplusplus.com/reference/forward_list/forward_list/insert_after/) to insert **num** Meerkat objects into the end of list2. This is more
difficult than it seems at first.
I recommend that you use an iterator to iterate to the last element in the forward_list
and then insert the Meerkat. This will involve a **for** or **while** loop.
Be sure to time this operation and display the information for the user. Try inputting
progressively larger values of num to see the effects of the two algorithms (1000, 5000,
20000, 50000, etc).
Explain to the TA or the instructor why this approach takes so much more time.
What is the computational complexity of this task? Express your answer in Big O
notation.
