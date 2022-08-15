# LAB #2 – Arrays & Pointers
**You get 7 points for attending lab. You can earn the remaining 3 points by
finishing your work prior to the next lab. For extenuating circumstances, contact
your lab TAs and the instructor.**

**(7 pts) Review: Arrays, Structs, Pointers, etc.** <br/>
In this lab, you will create a dynamic two dimensional array of mult_div_values
structs (defined at the bottom of the page). The two dimensional array will be used to
store the rows and columns of a **multiplication and division table**. Note that the
table will start at 1 instead of zero. This prevents us from causing a divide by zero
error in the division table!
The program needs to read the number of rows and columns from the user as
command line arguments. You should display an error message if either input is not a
suitable integer. At the end of the program, prompt the user if they want to see this
information for a different size matrix. Make sure you do not have any memory leaks.

```
// One approach to handling the command line arguments...
rows=atoi(argv[1]);
cols=atoi(argv[2]);
// Now check that rows and cols are valid non-zero integers
// ...
```
For example, if you run your program with these command line arguments:
  **./prog 5 5**
  
Your program should create a 5 by 5 matrix of structs and assign the multiplication
table to the **mult** variable in the struct and the division of the indices to the div
variable in the struct. The **mult** variable is an integer, and the div variable needs to
be a float (or double).

```
struct mult_div_values {
  int mult;
  float div;
};
```

Your program needs to be well-modularized. This means you will have specialized
functions... a function that checks if the rows and cols are valid, non-zero integers,
**bool is_valid_dimensions(char \*m, char \*n)**, and another function that creates the
matrix of structs given the m x n dimensions,
**mult_div_values\*\* create_table(int m, int n).**
In addition, you need to have functions that set the multiplication and division values,
as well as delete your matrix from the heap:
  **void set_mult_values(mult_div_values \*\*table, int m, int n)**
  **void set_div_values(mult_div_values \*\*table, int m, int n)**
  **void delete_table(mult_div_values \*\*table, int m)**
  
Then, create functions to print the tables. After your code is functioning, test it using the
following approach:

**Example Run:**
```
./prog 5 t
You did not input valid dimensions. Goodbye!
./prog 5 5

Multiplication Table:
  1 2 3 4 5
  2 4 6 8 10
  3 6 9 12 15
  4 8 12 16 20
  5 10 15 20 25

Division Table:
  1.00 0.50 0.33 0.025 0.20
  2.00 1.00 0.67 0.50 0.40
  3.00 1.50 1.00 0.75 0.60
  4.00 2.00 1.33 1.00 0.80
  5.00 2.50 1.67 1.25 1.00

Would you like to see a different size matrix (0-no, 1-yes)?
1

How many rows? 3
How many columns? 4

Multiplication Table:
  1 2 3 4
  2 4 6 8
  3 6 9 12
  
Division Table:
  1.00 0.50 0.33 0.025
  2.00 1.00 0.67 0.50
  3.00 1.50 1.00 0.75
  
Would you like to see a different size matrix (0-no, 1-yes)?
0
```
**(3 pts) Interface, Implementation, and Makefile**
Since we now have function prototypes and a struct that is a global user-defined type,
then we might want to begin making an interface file that holds all this information for us.
Create a **mult_div.h** interface file that will contain all the function and struct declaration
information we need:
```
struct mult_div_values {
  int mult;
  float div;
};
```
bool is_valid_dimensions(char \*, char \*);
mult_div_values\*\* create_table(int, int);
void set_mult_values(mult_div_values \*\*, int, int);
void set_div_values(mult_div_values \*\*, int, int);
void delete_table(mult_div_values \*\*, int);

After creating this **mult_div.h** file you need to **#include** it into your implementation
file (the file with a .cpp extension). You also need to remove the prototypes and
struct definition from your implementation file (e.g. delete the original
prototype/struct definition lines from the .cpp file).

> #include “mult_div.h”

Now, compile your program normally:
**g++ mult_div.cpp -o mult_div**

Let’s take this a step further, and keep only your function definitions in this
implementation file, i.e. **mult_div.cpp**, and put your main function in a separate
implementation file called **prog.cpp**. Your prog.cpp file will have to include the
mult_div.h file too. But, now how do we put these two files together? We have to
compile them together, i.e. **g++ mult_div.cpp prog.cpp -o mult_div**

What if we had 1,000 implementation (.cpp) files? We do not want to do this manually
anymore, right? There is a built-in UNIX/Linux script that makes this easy! This is
called a Makefile. Just vim Makefile to create it. Now, modify the file following the
pattern shown below.
**Note that the leading whitespace must be a tab character (you can’t simply use
spaces)!**

```
<target>:
  <compiler> <file1.cpp> <file2.cpp> -o <target>
```
 
**Example:**
```
mult_div:
  g++ -Wall -std=c++11 mult_div.cpp prog.cpp –o mult_div
```

**Note:** I added the extra text: “-Wall -std=c++11”. I always encourage students to
use these settings (the compiler will support extra features and print more detail).
Now, save and exit the file. You can type **make** in the terminal to now run this file.

Let’s learn a little more… We can **add variables to the file** and make **compiling
happen in different stages** by stopping g++ after compiling and before running it
through the linker. This creates object files, i.e. .o files, which you can link together.

```
CC = g++ -Wall -std=c++11
exe_file = mult_div
$(exe_file): mult_div.o prog.o
  $(CC) mult_div.o prog.o –o $(exe_file)
mult_div.o: mult_div.cpp
  $(CC) –c mult_div.cpp
prog.o: prog.cpp
  $(CC) –c prog.cpp
```

Try to make your program again. Notice all the stages. In addition, we usually add a
target for cleaning up our directory...
```
clean:
  rm –f *.out *.o $(exe_file)
.PHONY: clean
```
Now, we can run the specific target by typing “make <target>”, i.e. make clean

**Remember**, you and your partner **will not receive lab credit if you do not get
signed in** before leaving each lab. Once you have a zero on a lab, then it cannot
be changed because we have no way of know if you were there or not!!!
