## Introductory Information
According to a [2019 survey] (https://www.nfhs.org/media/1020412/2018-19_participation_survey.pdf) by the National Federation of State High School Associations, football is one of Oregon's most popular sports for students in high school. Online spreadsheets are available that contain 100 years of high school football records. In this project you will be processing historical data and presenting it in a form that is more user friendly.<br/>

Your employer has provided you with text files that contain information about various high schools and corresponding football matches. You will use C++ to parse the provided text file and read the information into variables that are useful for your design. The remainder of this document explains what your program needs to accomplish.

## Requirements
**Command Line Argument:**
When starting the program, the user will provide one command line argument. The command line argument will be the name of the file that contains the information about schools and football matches. Your program will open the specified file and parse the contents. If the user does not provide the name of an existing file the program should print out an error message and quit.

**Sorting and Printing:**
Once the program begins, the user should be prompted with a list of different ways to utilize the historical information.

**Available Options:**
- Display each school's earliest year on file: print each school's name, along with the year of its first recorded football game. Each entry must also display the city where the school is located and the school's moniker. The ordering of these entries is up to you.
- Best year (by points): You must process all of the Match entries and compute the total number of points that were scored (by the home team) during each year. You will then determine which year was the "best" year for the school, based on the highest number of points scored. After calculating the sum you will print the following information for each school (sorted in alphabetical order by name of school):
  - The name of the school
  - The year that had the most points scored by the home team
  - The total number of points that the home team scored in that particular year
  - Extra credit (5 pts): Also display a list of all the opponent teams that the school beat during their best year.
- Sort schools by overall historical performance: If the user picks this option the schools must be displayed in descending order by their historical winning ratios (i.e. sorted by winRatio). (You also need to print the name of the school.)
- Quit: The program will exit.
Your program should continue sorting and printing/writing until the user chooses to quit. For the sorting functionality, you can write your own sorting function, or consider using C++'s built in sort function. 

## Required Structs:
The following structs are required in your program. They will help organize the information that will be read in (or derived) from the files. You cannot modify, add, or take away any part of the struct.

The **School** struct will be used to hold information about each school.

Note that the struct contains a member variable named "winRatio". That particular value is derived from the total number of wins, losses, and ties in the school's history. From a mathematical perspective:

winRatio = (total # of wins) / ((total # of wins) + (total # of losses) + (total # of ties))

The **School** struct is defined as follows:

```
struct School {
  string name;
  string moniker;
  string city;
  double winRatio;
  int numMatches;  // added on June 28th
  struct Match* array;
};
```
The **Match** struct will hold information about the individual football matches.
```
struct Match {
  unsigned int year;
  unsigned int homeScore;
  string opponentName;
  unsigned int opponentScore;
};
```
## Required Functions:
You must implement the following functions in your program. You are not allowed to modify these required function declarations in any way.
*Note #1: it is acceptable if you choose to add additional functions (but you must still include the required functions).*
*Note #2: You must write the dynamic memory allocation functionality yourself (i.e. no using vectors).*

This function will dynamically allocate an array of schools (of the requested size):
```
School* create_school_array(int);
```
This function will fill a School struct with information that is read in from the text file. *Hint: “ifstream &” is a reference to a filestream object. You will need to create one and pass it into this function to read from the input text file.*
```
void load_school_data(School*, int, ifstream &); 
```
This function will dynamically allocate an array of matches (of the requested size):
```
Match* create_match_array(int);
```
This function will fill a Match struct with information that is read in from the text file.
```
void load_match_data(Match*, int, ifstream &); 
```
You need to implement a function that will delete all the memory that was dynamically allocated. You can choose the prototype. A possible example prototype includes the following:
```
void delete_school_data(School*, int);
```
## Required Input File Format
Your program must accommodate the file format as specified in this section. The file content will be provided in sets (corresponding to each school). Furthermore, each school will be accompanied by a listing of the historical football matches.

Each input file will follow the format shown below.

A sample file is available for download [here]([https://pages.github.com/](https://web.engr.oregonstate.edu/~goinsj/resources/CS162_U22/assignments/athletic_records/sample_1.txt)
Important observation: a semicolon is used to separate the individual fields on each line.
```
<total number of schools in file (integer)>
<name of first school>;<moniker>;<city>;<number of matches in school history>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
...
<name of first school>;<moniker>;<city>;<number of matches in school history>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
...
<name of third school>;<moniker>;<city>;<number of matches in school history>
<year>;<home score>;<opponent name>;<opponent score>
<year>;<home score>;<opponent name>;<opponent score>
...
```

## Example Operation
The following snippet of text shows an example implementation of the athletic record program. Note that this example does not illustrate all required behavior. You must read this entire document to ensure that you meet all of the program requirements.

Note: the filename is provided as a command line argument. It's not hard-coded (the TA could provide any valid filename while testing your code).

```
$ ./assign1 sample_1.txt

Which option would you like to choose?
Display each school's earliest year on file (Press 1):
List the best year (by points acquired) for each school (Press 2):
Sort schools by overall historical performance (win ratio) (Press 3):
Quit (Press 4):
3
Sunnyview HS: 0.714
Subrosa HS: 0.5
Mediocre Heights: 0.167

Which option would you like to choose?
Display each school's earliest year on file (Press 1):
List the best year (by points acquired) for each school (Press 2):
Sort schools by overall historical performance (win ratio) (Press 3):
Quit (Press 4):
2
Mediocre Heights: 87 points in 1949
Subrosa HS: 359 points in 2004
Sunnyview HS: 303 points in 2000

Which option would you like to choose?
Display each school's earliest year on file (Press 1):
List the best year (by points acquired) for each school (Press 2):
Sort schools by overall historical performance (win ratio) (Press 3):
Quit (Press 4):
3
Sunnyview HS: 0.714
Subrosa HS: 0.5
Mediocre Heights: 0.167

Which option would you like to choose?
Display each school's earliest year on file (Press 1):
List the best year (by points acquired) for each school (Press 2):
Sort schools by overall historical performance (win ratio) (Press 3):
Quit (Press 4):
1
Subrosa HS, "Lions", Team founded: 2003, City: Portland
Sunnyview HS, "Sailors", Team founded: 1999, City: Sunnyview
Mediocre Heights, "Mavericks", Team founded: 1948, City: Jade Harbor

Which option would you like to choose?
Display each school's earliest year on file (Press 1):
List the best year (by points acquired) for each school (Press 2):
Sort schools by overall historical performance (win ratio) (Press 3):
Quit (Press 4):
4
```
## Programming Style/Comments
In your implementation, make sure that you include a program header. Also ensure that you use proper indentation/spacing and include comments! Below is an example header to include. Make sure you review the [style guidelines for this class] (https://web.engr.oregonstate.edu/~goinsj/resources/general/cpp_style_guideline.pdf), and begin trying to follow them, i.e. don’t align everything on the left or put everything on one line!

```
/******************************************************
** Program: read_file.cpp
** Author: 
** Date: 
** Description:  
** Input:
** Output:
******************************************************/
```

When you compile your code, it is acceptable to use C++11 functionality in your program. In order to support this, change your Makefile to include the proper flag.
For example, consider the following approach (note the inclusion of -std=c++11):

```
g++ -std=c++11 //other flags and parameters
```

In order to submit your homework assignment, you must create a tarred archive that contains any .h and .cpp files that you wrote. You also need to include a Makefile. This tar file will be submitted to Canvas. In order to create the tar file, use this approach (where the first parameter is the desired output file name):

```
tar -cvf assign1.tar read_file.h read_file.cpp prog.cpp Makefile
```
Note: I simplified the requirements for this first homework assignment. You do not have to divide your code into separate files (everything can be contained in a single .cpp file). A Makefile is also optional for the first homework assignment.
