# Zoo Tycoon
## Motivation
The goal of this assignment is to start working with inheritance and polymorphism in C++.  As you implement your program you'll also expand your knowledge and familiarity of object-oriented programming.

## Problem Statement
For this assignment, you will implement a small game where the player acts as the owner of the city's zoo, which has exhibits of monkeys, sea otters, and meerkats. As the owner, it's the player's job both to ensure the welfare of the animals and to generate as much profit as possible. They accomplish these goals by investing in animals, feeding them, caring for them when they are sick, and raising their babies when they are born.

Each species of animal has these specific traits:

- **Age**
  - For all species, an animal is a baby if it is less than 7 weeks old.
  - For all species, an animal is an adult if it is at least 2 years old.
  - For our purposes the age range between 7 weeks and 2 years can be considered as adolescence. The animal is no longer a baby but is not yet capable of reproducing.
- **Cost**
  - Monkeys cost $12,000 each.
  - Sea otters cost $4,000 each.
  - Meerkats cost $500 each.
- **Babies**
  - Monkeys have 1 baby at a time.
  - Sea otters have 1 baby at a time.
  - Meerkats have 3 babies at a time.
- **Food cost**
  - Monkeys have a weekly food cost of 4 times the base food cost.
  - Sea otters have a weekly food cost of 2 times the base food cost.
  - Meerkats have a weekly food cost equal to the base food cost.
- **Revenue**
  - Each animal generates weekly revenue equal to a percentage of the initial cost of one of its species.
    - All animals except monkeys generate 5% of the cost of one of their species (i.e. each sea otter generates $200 each week, and each meerkat generates $25 each week).
    - Each monkey generates 3% of the cost of a monkey (i.e. each monkey generates $360 each week).
  - On certain weeks, when attendance is high, each monkey generates some amount of bonus revenue. See below for details.

## Game Flow
The game starts with the owner having no animals and $100,000 in the bank, and it proceeds one week at a time. You can think of each week as a turn for the player. During a single week, several things happen. Note: As long as your implementation follows the spirit of the assignment, it's okay to have minor differences.

1. The age of each animal currently in the zoo increases by 1 week (note that you can track time in days if you prefer).
2. A special event occurs. The special event is chosen at random from among the following options:
    - One randomly chosen animal gets sick. In order to care for the sick animal, the owner must pay an amount equal to 20% of the initial cost of an animal of the same species as the sick animal (e.g. a sick monkey costs 20% of $12,000, i.e. $2400). If the owner has enough money to cover this cost, it is subtracted from their bank account. If they do not have enough money, then the sick animal dies and is removed from the zoo.
    - A randomly chosen adult animal gives birth to the appropriate number of babies for its species (a non-adult can't have babies). Note: this can only happen when the zoo owns two or more animals of the same species. Each baby starts with age 0 and is added into the zoo.
    - A boom in zoo attendance occurs. Each time this happens, each monkey generates a random amount of extra bonus revenue between $500 and $1200.
    - No special event occurs during this week.
3. The owner receives weekly revenue for each animal, as specified above.
4. The owner may buy up to 100 adult animals of a single species each week (clarified on 7/27) (you must reject purchase requests that would exceed the available cash balance). The owner may only buy one species per week, but they do not have to buy any animals if they don't want to. Each animal that the owner buys is exactly 2 years old. When the owner buys an animal, the cost of the animal is subtracted from the owner's bank account.
5. The owner must pay the upcoming feeding cost for each animal in the zoo (including any they just bought). The cost of food for each animal is calculated using the base cost of food ($25). Once the cost of food for each animal is calculated, this amount is subtracted from the owner's bank account.

In addition to the specifications above, your game must have these features:
- Each animal less than 7 weeks old (a baby) generates twice the amount of revenue as an adult animal. These babies (who are less than 7 weeks old) also cost twice as much as an adult if they get sick.
- If the player runs out of money at any point, the game ends with the zoo going bankrupt.

## Other Program Requirements
- You must have a class for each of the following things: **Zoo**, **Animal**, **Monkey**, **SeaOtter**, and **Meerkat**.
- You must use inheritance: the classes for monkey, sea otter, and meerkat must inherit some traits and behaviors from the animal class, though each of them may also have unique traits or behaviors, as well (e.g. the bonus payout for monkeys).
- Within your zoo, you must store all exhibits inside a dynamically-allocated array that holds variables of type: Animal*. To reiterate, you MUST store your exhibit as an array of pointers to Animals. There should be only one array to hold all the animals that are purchased (even if they are different types).
- Your program should implement the game flow described above. The player may play one week at a time until they choose to quit the game. At the beginning of each week, you should let the player know how much money they have in the bank and display a table of currently owned animals. Be sure that your table also includes information about the number of babies, adolescents, and adult animals of each species.
- Your program may not have any memory leaks. I strongly recommend that you use Valgrind to occasionally test your program as you develop it (even when everything seems to be working).
- Your program must be factored into **interface, implementation, and application files**. Specifically, you should have one header file and one implementation file for each class, and you should have a single application file containing your main() function. You should also include a Makefile that handles compilation for your program.
- No use of libraries that have not been presented in the course (this prohibition is especially targeted towards <vector> or other container classes).
- Failure to use polymorphism will incur a 50 point penalty. You must follow the spirit of the assignment.

## Hints
**This program requires the implementation of several new object-oriented concepts. Make sure that you start early and do not procrastinate!**
Polymorphism only works when you are working with references or pointers. If you use the value of an object directly, it may not select the correct member function.

## Extra Credit
~~In addition to the requirements above, you may earn extra credit as follows:~~
- ~~(4 points) Implement "fast-forward" functionality. When you prompt the player to purchase new animals, also provide an option to skip a user-specified number of weeks. For example, the player can choose to skip ahead and enter the number "8" which will then auto-play the next 8 weeks of the game. Your game will then proceed to simulate the next 8 weeks. Be sure to print a summary table that displays all relevant information for the skipped time period (i.e. the birth of new animals, any deaths, remaining cash balance, number of babies, adolescents, and adult animals of each species, etc). If the zoo goes bankrupt the game must display the summary table and then gracefully exit (after informing the player that they lost).~~

## Implementation Details
For this assignment you have additional freedom to design your own implementation (as long as you use inheritance and polymorphism). There are certain baseline requirements as specified in this document. However, the exact member functions and member variables are up to you. (Hints will be provided in class.)

**PLEASE...** take the time to design your program on paper. Use scratch paper with flow charts or pseudo-code. In particular, think of how your program will flow. What will the constructors do? How will you pass objects and variables between different classes? The old adage "Measure twice, cut once" could certainly be applied to CS162 as "Design twice, program once".

Taking the time to do a thorough program design can save you hours of frustrating debugging time!
  
## Programming Style/Comments
In your implementation, make sure that you include a program header. Also ensure that you use proper indentation/spacing and include comments! Below is an example header to include. Make sure you review the [style guidelines for this class](https://web.engr.oregonstate.edu/~goinsj/resources/general/cpp_style_guideline.pdf), and begin trying to follow them, i.e. don’t align everything on the left or put everything on one line!

```
/******************************************************
** Program: zoo_tycoon.cpp
** Author: Your Name
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
tar -cvf assign3.tar list_of_all_the_.h_and_.cpp_files Makefile
```
