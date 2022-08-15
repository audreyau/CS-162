# Hunt the Chimera
## Motivation
The goal of this assignment is to expand your knowledge of polymorphism and C++ template classes from the STL (standard template library).

## Introduction
Hunt the Chimera is a game set inside the cave of the Chimera, a scary, gold-hoarding, fire-breathing monster who likes to eat people who disturb its sleep. The player's goal is to guide an adventurer to kill the Chimera, find its hidden gold, and escape alive. The Chimera lives in a large cave of rooms arranged in a grid, where each room has four tunnels leading to the rooms to the north, east, south, and west.

The adventurer starts the game in a random empty room in the Chimera’ cave. Her starting position is also the location of the escape rope that she must use to escape after she's completed her task.

Each room may be empty, or it may contain one (and only one) of four "events" (all described below): two kinds of dangerous hazards, the terrifying Chimera, and the gold treasure. When the adventurer is in a room that’s adjacent to one containing an "event", the player will receive a percept (a message) to inform them about the event the adventurer is close to.

If the adventurer perishes while searching for the Chimera, the player should be presented with the option to start the game over with the same cave configuration, start the game over with a new random cave configuration, or quit the game entirely.

The player wins the game if they can safely guide the adventurer through the cave to kill the Chimera, pick up the gold, and make it back to the escape rope unharmed! Note: If you enter the cave, retrieve the gold, and escape without killing the Chimera, that's okay too. The player still wins. Your program header (in the main.cpp file) needs to specify whether the Chimera must be killed in order to win the game.

## Game elements
### The adventurer
Each turn you may take one of two actions to guide the adventurer:
- **Move:** You can move through a tunnel to an adjacent room.
- **Fire an Arrow:** The adventurer begins the game with three arrows. As long as the adventurer still has at least one arrow, the player can choose to fire one in any direction (i.e. north, south, east, or west). The arrow continues flying in the same direction until it hits a wall or travels through three rooms. If the arrow enters the Chimera’ room, it pierces the Chimera’ heart and kills the monster. As noted above, if you want to design the game such that the player can win by safely retrieving the gold (and not killing the Chimera), that's okay too.

### The Chimera
Usually, the Chimera is peacefully asleep in its cave. Two things wake the Chimera up, however: the adventurer entering its room or shooting an arrow and missing it. If the Chimera wakes up while in the same room as the adventurer, the Chimera will angrily eat the adventurer, ending the game. If the Chimera just wakes up from hearing an arrow being fired (anywhere else in the cave) it will move to a random empty room in an attempt to avoid being found.

### Hazards
There are two kinds of hazards in the Chimera' cave:
- **Lava:** Two of the cave's rooms contain floors that are covered with lava. If the adventurer enters a room containing lava, she falls in and dies, and the player loses.
- **Super bats:** Two rooms have super bats. If the adventurer enters a room that contains super bats, an angry bat grabs her and takes her to a random empty room in the cave. Added August 3rd: the angry bat will then return to its starting point.

### The gold
The gold is a treasure sitting in a room that contains neither a hazard nor the Chimera. If the adventurer is in a room containing the gold, she automatically picks it up and takes it with her.

### Percepts
When the adventurer is in a room directly adjacent to a room containing an "event", the player receives the following messages:

- **Chimera:** "You smell a terrible stench."
- **Super bats:** "You hear wings flapping."
- **Lava:** "You feel an intense blast of heat."
- **Gold:** "You notice the shine of bullion in the distance."

Notice that there’s no percept for the escape rope! That means the player will have to remember where they started and find their way back to that tile after they’ve completed their task.

As an example of how the percepts work, if the adventurer is standing in an empty room with the Chimera one room to the North, the Gold one room to the East, and Bats two rooms to the South, they would receive the following messages at the beginning of their turn:

```
You smell a terrible stench.
You notice the shine of bullion in the distance.
```

Remember, the percepts don’t tell you where the hazard or gold is, just that it’s somewhere close!

## Program requirements
- Your program should allow the user to play Hunt the Chimera, as described above.
- The Chimera' cave is represented by a square grid. The size of the grid (i.e. the number of rooms on one side of the square) should be specified as a **command line parameter to your program**. Caves smaller than four rooms on a side aren't allowed. You should visualize the grid to allow the user to play the game. In particular, you should display the grid, and indicate within the grid which room the player is in. An example visualization of a 4x4 grid might look like this, where the * character represents the location of the adventurer:

```
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   | * |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
```

- Your program **must also accept a second command line parameter** which will be either "true" or "false". If the parameter is set to false (e.g. **./Chimera 4 false**) then the program will run as normal. If the second command line value is specified as "true" then your game must operate in debug mode.
- When your program in operating in debug mode, the player's map will show a "cheat view" with locations marked for each of the following: Chimera, bats, lava, gold, player, escape rope.
- To navigate the cave system, the player must be able to type "w" (north), "a" (west), "s" (south), or "d" (east). In order to fire an arrow, a space (" ") should be used, followed by either "w", "a", "s", or "d" to indicate the direction. For example, the user would enter " d" to fire an arrow towards the east.
- Your code must have the following classes: Room, Event, Chimera, Bats, Lava, and Gold. You may create more classes if they would be helpful.
- The Event class **must be abstract**, and the Chimera, Bats, Lava, and Gold classes should all be derived from Event. Remember, any event does something when the adventurer enters the same room as the event, and will display a message when the adventurer is nearby. Your design of the Event class should reflect this. For example, your Event class might have a percept() method that is called whenever the adventurer is in a room adjacent to the event, where the Chimera, Bats, Lava, and Gold classes implement their own specific versions of the percept() method. Similarly, your Event class might have an encounter() method that is called when the adventurer enters the same room as the event, with the individual event classes implementing their own specific versions of encounter().
- **You must use the Event classes polymorphically.** In other words, your Room class may only contain a pointer to an event (Event*) but not members of the Chimera, Bats, Lava, or Gold classes.
- Each Room contains at most one Event, but it's possible that it contains no Event. The design of your Room class should reflect this.
- The grid representing your cave should be implemented using the std::vector class.
- Your program may not have any memory leaks. I strongly recommend that you use Valgrind to occasionally test your program as you develop it (even when everything seems to be working).
- The Big 3 must be implemented as appropriate.
- Your program must be factored into interface, implementation, and application. Specifically, you should have one header file and one implementation file for each class, and you should have a single application file containing your main() function. You should also include a Makefile that specifies compilation for your program.
- Lack of correct coding style will incur an automatic 6 point deduction. You must follow the spirit of the assignment.

## Hints
- Polymorphism only works when you are working with references or pointers. If you use the value of an object directly, it may not select the correct member function.
- Hunt the Chimera is a game all about hiding information from the player, which might make it hard to debug! Your life will be easier if you implement the debugging mode first and then finish your implementation of the final version

## Extra Credit
In addition to the requirements above, you may earn extra credit as follows:
- (6 points) Implement a custom class that plays the game for you. This class should use the same interface to the game that the player does. That is, it should use percepts to learn about the world and make decisions.
Implementation Details
As with the previous program, you have additional freedom to design your own implementation. There are certain baseline requirements as specified in this document. However, the exact member functions and member variables are up to you.

Be sure to design your program on paper. Use scratch paper with flow charts or pseudo-code. In particular, think of how your program will flow. What will the constructors do? How will you pass objects and variables between different classes? Taking the time to do a thorough program design can save you hours of frustrating debugging time!

On the topic of debuggers, I strongly recommend that you choose a debugger and get familiar with its operation (GDB, Visual Studio, etc). As your programs get more complex it becomes even more useful to instantly know the value of all your variables and memory contents.

## Programming Style/Comments
In your implementation, make sure that you include a program header. Also ensure that you use proper indentation/spacing and include comments! Below is an example header to include. Make sure you review the [style guidelines for this class](https://web.engr.oregonstate.edu/~goinsj/resources/general/cpp_style_guideline.pdf), and begin trying to follow them, i.e. don’t align everything on the left or put everything on one line!

```
/******************************************************
** Program: Chimera.cpp
** Author: Your Name
** Date: 08/xx/2022
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
tar –cvf assign4.tar list_of_all_the_.h_and_.cpp_files Makefile
```
