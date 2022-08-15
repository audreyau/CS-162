# LAB #4 – The Big 3
This lab will introduce the concept of a **copy constructor** function and **assignment
operator overload** function. In combination with the **destructor**, these three functions
are known as The Big 3. There is a well-known rule of thumb… if you find yourself
needing to implement any of The Big 3, you should take the time to implement each of
the three functions. In other words, these three functions are considered “all-or-nothing”.

A tar file is provided on the lab website with template files for a **Dictionary** class. In
order to download and extract the tar file into your engineering space, run the following
commands:
```
mkdir lab4
cd ./lab4
wget https://web.engr.oregonstate.edu/~goinsj/resources/CS162_U22/labs/lab4.tar
tar xf ./lab4.tar
# the files will now be extracted to the directory
```

First, implement a new public member function inside Dictionary with the following
prototype: **void display()**. In the main.cpp file you should be able to call this function
and your code will print all entries in the dictionary (along with their alternate
spellings).

Add the following function call to main.cpp and compile the code.
```
d1.display();
```

Does the function work correctly? You should see information about the entries for
island and jeopardy.

Since the dictionary class involves dynamic memory, it needs to implement The Big
3. Review the provided code and look at the empty function definitions that are
provided as templates. For this part of the lab, **leave the function templates as-is.**

Next, add the following lines of code to main.cpp:
```
Dictionary d2;
d2 = d1;
```

Compile this code. What do you see printed on the screen? Make sure that you
understand why each function was invoked.

The assignment operator overload is invoked **when an existing object is set equal
to another existing object**. That’s why the line “d2 = d1” caused the assignment
operator overload to be called. The copy constructor is very similar with a slight
change… the copy constructor is invoked **when a brand new object needs to be
cloned from an existing object.**

In order to observe this behavior, add an additional line of code to **main.cpp**:
```
Dictionary d3 = d1;
```
Compile this code. What do you see printed on the screen? Make sure that you
understand why each function was invoked.

Now let’s illustrate why the Big 3 are necessary. Try to display the contents of the
dictionary d2 (inside main.cpp). Side note: depending on your implementation, this
might crash your program (that’s okay).
```
d2.display();
```

Even if your code executed without crashing, d2 will not contain the correct copy of
d1 since the assignment operator overload (implemented in dictionary.cpp) is not
copying any data. In order to properly fix this problem, you need to implement The
Big 3.

Notice that the dictionary.cpp file already contains (nearly) empty function definitions
for these two functions. The destructor is already implemented for you so don’t worry
about that part. You simply need to add the correct code for the assignment operator
overload and copy constructor. **Do not remove the COUT statements that are
already present in those functions.** This will be useful when testing your code.

Once you have implemented the assignment operator overload and copy
constructor, test it by ensuring that the following code (added to main.cpp) displays
the correct output.
```
 Dictionary src, book2;
 src.add_word("island", "ilande", "ylonde");
 Dictionary book1 = src;
 book1.add_word("february", "feverere", "feverell");
 book2 = book1;
 book2.add_word("jeopardy", "yeopardie", "ieoperde");
 
 cout << "Contents of src: " << endl;
 src.display();
 cout << "Contents of book1: " << endl;
 book1.display();
 cout << "Contents of book2: " << endl;
 book2.display();
```
**To get points for the lab, show your TA (or instructor) that all of the functions are
working as expected. You should test that they are called at the appropriate
times. This may be done by leaving the print statements in the functions.**
