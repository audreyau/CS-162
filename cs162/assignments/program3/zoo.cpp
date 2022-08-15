#include <iostream>
#include <cstdlib>

#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"

using namespace std;

//intialize static variables
int Zoo::twoYearOldAnimal = 104;

/*********************************************************************
** Function: Zoo ()
** Description: default constructor
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: intializes member variables and allocates memory for roster
*********************************************************************/
Zoo::Zoo () {
    //intialize member variables
    capacity = 10;
    numAnimals = 0;
    numWeeks = 0;
    attendance = 0;
    again = 1;
    valid = true;
    bankBalance = 100000;
    bankrupt = 0;

    //allocate HEAP memory for roster
    roster = new Animal* [capacity];
    for (int i = 0; i < capacity; i++) {
        roster[i] = nullptr;
    }
}

/*********************************************************************
** Function: ~Zoo ()
** Description: destructor
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: deletes HEAP memory when Zoo obj is no longer needed
*********************************************************************/
Zoo::~Zoo () {
    for (int i = 0; i < numAnimals; i++)
        delete roster[i];

    delete[] roster;
}

/*********************************************************************
** Function: zooTycoon ()
** Description: contains basic structure for the game in a do while loop
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: cycles through rounds until bankrupt or player quits
*********************************************************************/
void Zoo::zooTycoon () {
    do {
        announceRound ();
        initiateRound ();
        ageAnimals ();
        verifyPlayablity ();
    } while (valid);

    if (!valid) {
        cout << "-----------------------" << endl << endl;
        cout << "You finished with $" << bankBalance << " and " << numAnimals << " animals:" << endl;
        displayTable ();
    }
}

/*********************************************************************
** Function: announceRound ()
** Description: prints basic info/data at the beginning of each round
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: prints week number, bank balance, num animals, shows animals
*********************************************************************/
void Zoo::announceRound () {
    numWeeks ++;

    cout << "------------------------------------------------" << endl << endl;
    cout << "\u001b[1m[IT IS WEEK " << numWeeks << "...]\u001b[0m" << endl;
    cout << "Your bank has: $" << bankBalance << "."  << endl;
    cout << "You have " << numAnimals << " animals." << endl;

    displayTable ();
    cout << endl;
}

/*********************************************************************
** Function: initiateRound ()
** Description: initiates the first half of a round (random event, calculate revenue)
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: prints necessary info, displays, questions
*********************************************************************/
void Zoo::initiateRound () {
    double tmp, monkeyBonus = 0;
    attendance = 0;

    randomEvent ();

    double originalBalance = bankBalance;
    for (int i = 0; i < numAnimals; i++) {
        if (attendance == 1 && (roster[i] -> getType () == 0)) {
            tmp = roster[i] -> calculateRevenue (attendance);
            monkeyBonus = monkeyBonus + (tmp - roster[i] -> calculateRevenue (0));
            bankBalance = bankBalance + tmp;
        }

        else
            bankBalance = bankBalance + (roster[i] -> calculateRevenue (attendance) );
    }

    initiateRoundCont (monkeyBonus, originalBalance);
}

/*********************************************************************
** Function: initiateRoundCont (double, double)
** Description: initiates the second half of a round (revenue, shop, feeding)
** Parameters: double monkeyBonus, double originalBalance
** Pre-Conditions: Zoo class
** Post-Conditions: prints necessary info, displays, questions
*********************************************************************/
void Zoo::initiateRoundCont (double monkeyBonus, double originalBalance) {
    cout << "\u001b[1m[REVENUE]\x1b[0m" << endl;
    cout << "This week, you made a total profit of $" << bankBalance - originalBalance << "." << endl;

    if (attendance == 1) 
        cout << "► The spike in attendance gave you an additional revenue of $" << monkeyBonus << "! Otherwise, you would have made a total profit of only $" << bankBalance - originalBalance - monkeyBonus << "." << endl;
    
    cout << "► In total, your bank has: $" << bankBalance << endl << endl;

    shop ();
    feedAnimals ();

    cout << endl << "-----------------------" << endl << endl;
    cout << "In total, your bank account has: $" << bankBalance << endl;
}

/*********************************************************************
** Function: ageAnimals ()
** Description: increases all animals' ages by 1 week
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: increments ages
*********************************************************************/
void Zoo::ageAnimals () {
    for (int i = 0; i < numAnimals; i++) {
        roster[i] -> incrementAge ();
    }
}

/*********************************************************************
** Function: verifyPlayablity ()
** Description: verifies that the game can continue
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: if bankrupt or choose not to play, game quits
*********************************************************************/
void Zoo::verifyPlayablity () {
    if (bankrupt == 1) {
        cout << "You went bankrupt!" << endl;
        valid = false;
    }

    else {
        cout << "\nWould you like to continue playing? (0-no, 1-yes): ";
        cin >> again;

        if (!(again == 0 || again == 1)) {
            do {
                cout << "  \u001b[31mPlease enter a valid number: \x1b[0m";
                cin >> again;
            } while (!(again == 0 || again == 1));
        }

        if (again == 0) 
            valid = false;
        
        cout << endl;
    }
}

/*********************************************************************
** Function: countAnimals (Animal*, int[], int[], int[])
** Description: counts the number of each animal  
** Parameters: Animal* ptr, int countTheMonkeys[], int countTheMeerkats[], int countTheSeaOtters[]
** Pre-Conditions: Zoo class
** Post-Conditions: stores in array of total, baby, teen, adult
*********************************************************************/
void Zoo::countAnimals (Animal* ptr, int countTheMonkeys[], int countTheMeerkats[], int countTheSeaOtters[]) {
    countMonkeys (ptr, countTheMonkeys);
    countMeerkats (ptr, countTheMeerkats);
    countSeaOtters (ptr, countTheSeaOtters);
}

/*********************************************************************
** Function: countMonkeys (Animal*, int[])
** Description: counts the number of Monkeys
** Parameters: Animal* ptr, int countMonkeys[]
** Pre-Conditions: Zoo class, is a monkey
** Post-Conditions: stores in array of total, baby, teen, adult
*********************************************************************/
void Zoo::countMonkeys (Animal* ptr, int countMonkeys[]) {
    if (ptr -> getType() == 0) {
        countMonkeys[0] ++;

        if (ptr -> getAge() < 7) {
            countMonkeys[1] ++;
        }
        else if (ptr -> getAge() >= twoYearOldAnimal) {
            countMonkeys[3] ++;
        }
        else {
            countMonkeys[2] ++;
        }
    }
}

/*********************************************************************
** Function: countMeerkats (Animal*, int[])
** Description: counts the number of Meerkats
** Parameters: Animal* ptr, int countMeerkats[]
** Pre-Conditions: Zoo class, is a meerkat
** Post-Conditions: stores in array of total, baby, teen, adult
*********************************************************************/
void Zoo::countMeerkats (Animal* ptr, int countMeerkats[]) {
    if (ptr -> getType() == 1) {
        countMeerkats[0] ++;

        if (ptr -> getAge() < 7) {
            countMeerkats[1] ++;
        } 
        else if (ptr -> getAge() >= twoYearOldAnimal) {
            countMeerkats[3] ++;
        }
        else {
            countMeerkats[2] ++;
        }
    }
}

/*********************************************************************
** Function: countSeaOtters (Animal*, int[])
** Description: counts the number of SeaOtters
** Parameters: Animal* ptr, int countSeaOtters[]
** Pre-Conditions: Zoo class, is a sea otter
** Post-Conditions: stores in array of total, baby, teen, adult
*********************************************************************/
void Zoo::countSeaOtters (Animal* ptr, int countSeaOtters[]) {
    if (ptr -> getType() == 2) {
        countSeaOtters[0] ++;

        if (ptr -> getAge() < 7) {
            countSeaOtters[1] ++;
        } 
        else if (ptr -> getAge() >= twoYearOldAnimal) {
            countSeaOtters[3] ++;
        }
        else {
            countSeaOtters[2] ++;
        }
    }
}

/*********************************************************************
** Function: displayTable ()
** Description: prints a table of info for animals owned
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: prints number of each by total, baby, teen, adult
*********************************************************************/
void Zoo::displayTable () {
    int countMonkeys [4] = {0}; //total, babies, adolescents, adults
    int countMeerkats [4] = {0};
    int countSeaOtters [4] = {0};

    for (int i = 0; i < numAnimals; i++) {
        countAnimals (roster[i], countMonkeys, countMeerkats, countSeaOtters);
    }
    
    cout << endl << "\u001b[7m Your Animals \x1b[0m";
    cout << " ---------------------------------" << endl;
    cout << "| \t\t" << "total\t" << "babies\t" << "teens\t" << "adults\t|" << endl;
    cout << "| Monkeys\t" << countMonkeys[0] << "\t" << countMonkeys[1] << "\t" << countMonkeys[2] << "\t" << countMonkeys[3] << "\t|" << endl;
    cout << "| Meerkats\t" << countMeerkats[0] << "\t" << countMeerkats[1] << "\t" << countMeerkats[2] << "\t" << countMeerkats[3] << "\t|" << endl;
    cout << "| Sea Otters\t" << countSeaOtters[0] << "\t" << countSeaOtters[1] << "\t" << countSeaOtters[2] << "\t" << countSeaOtters[3] << "\t|" << endl;
    cout << " -----------------------------------------------" << endl << endl;
}

/*********************************************************************
** Function: randomEvent ()
** Description: generates a random event out of 4 options
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: chooses a random event and triggers it
*********************************************************************/
void Zoo::randomEvent () {
    cout << "\u001b[1m[SPECIAL EVENT]\x1b[0m" << endl;
    int event = rand() % 4; //4 types

    //random animal gets sick
    if (event == 0) 
        sickAnimalEvent ();  

    //random animal gives birth
    else if (event == 1) 
        birthAnimalEvent ();

    //spike in attendance
    else if (event == 2) {      
        cout << "Your zoo received a spike in attendance! Any monkey you currently own generates extra revenue." << endl; 
        attendance = 1;
    }

    //nothing
    else 
        cout << "No special event this week (phew!)." << endl;
    
    cout << endl;
}

/*********************************************************************
** Function: sickAnimalEvent ()
** Description: intiates the option 0 of the random events
** Parameters: none
** Pre-Conditions: Zoo class, event == 0
** Post-Conditions: a animal becomes sick and is either healed or dies
*********************************************************************/
void Zoo::sickAnimalEvent () {
    if (numAnimals > 0) { 
        double payment;
        int sickAnimal = rand() % (numAnimals - 1);
        cout << "One of your " << announceType(roster[sickAnimal] -> getType ()) << "s is sick!" << endl;

        if ((roster[sickAnimal] -> getAge ()) < 7) {
            payment = 0.4 * (roster[sickAnimal] -> getPrice ());
            cout << "► Since the animal is a baby, you must pay: $" << payment << endl << endl;
        }
        else {
            payment = 0.2 * (roster[sickAnimal] -> getPrice ());
            cout << "► Since the animal is not a baby, you must pay: $" << payment << endl << endl;
        }

        cure (payment, sickAnimal);
    }

    else
        cout << "An animal becomes sick." << endl << "► Since you don't currently own any animals, you're off the hook!" << endl;
}

/*********************************************************************
** Function: cure (double, int)
** Description: determines whether the user can heal the sick animal
** Parameters: double payment, int sickAnimal
** Pre-Conditions: Zoo class, event == 0
** Post-Conditions: if heal, money subtracted; if not healed, removed from roster
*********************************************************************/
void Zoo::cure (double payment, int sickAnimal) {
    if (bankBalance - payment > 0) {
        bankBalance = bankBalance - payment;
        cout << "► You successfully cured your animal." << endl << "► Your bank balance is now: $" << bankBalance << endl;
    }
    else {
        removeAnimal (roster[sickAnimal], sickAnimal);
        cout << "► You don't have enough money. Your animal dies and is removed from the zoo." << endl;
    }
}

/*********************************************************************
** Function: cure (Animal*, int)
** Description: if user doesn't have enough money, the sick animal is removed from the zoo
** Parameters: Animal* sickAnimal, int indexToGrab
** Pre-Conditions: Zoo class, event == 0, animal not healed
** Post-Conditions: animal removed from roster
*********************************************************************/
void Zoo::removeAnimal(Animal* sickAnimal, int indexToGrab) {
    Animal** temp = new Animal* [capacity];
    delete roster[indexToGrab];

    for (int i = 0; i < numAnimals - indexToGrab; i++) {
        roster[indexToGrab + i] = roster[indexToGrab + i + 1];
    }
    roster[numAnimals] = nullptr;

    for (int i = 0; i < numAnimals; i++) {
        temp[i] = roster[i];
    }

    if (roster!= NULL) {
        delete[] roster;
    }

    roster = temp;
    numAnimals --;
}

/*********************************************************************
** Function: birthAnimalEvent ()
** Description: intiates the option 1 of the random events
** Parameters: none
** Pre-Conditions: Zoo class, event == 1
** Post-Conditions: if 2 adult animals of one species in zoo, give birth
*********************************************************************/
void Zoo::birthAnimalEvent () {
    int parents = 0, parentIndex = 0;
    int possiblities[3];

    randomizeAnimal (possiblities);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numAnimals; j++) {
            if ((roster[j] -> getType () == possiblities[i]) && (roster[j] -> getAge () >= twoYearOldAnimal)) {
                parents ++;
                parentIndex = j;
            }
        }
        if (parents >= 2) 
            break;

        parents = 0;
    }

    delivery (parents, parentIndex);
}

/*********************************************************************
** Function: randomizeAnimal (int[])
** Description: randomizes the order in which the code will look for 2 parents
** Parameters: int possiblities[]
** Pre-Conditions: Zoo class, event == 1
** Post-Conditions: creates array containing {0,1,2}, shuffled
*********************************************************************/
void Zoo::randomizeAnimal (int possiblities[]) {
    int randomIndex, temp;

    for (int i = 0; i < 3; i++)
        possiblities[i] = i; 

    for (int i = 0; i < 3; i++) {
        randomIndex = rand() % 3;
        temp = possiblities[i];
        possiblities[i] = possiblities[randomIndex];   
        possiblities[randomIndex] = temp;
    }
}

/*********************************************************************
** Function: delivery (int, int)
** Description: the birth of an animal!
** Parameters: int parents, int parentIndex
** Pre-Conditions: Zoo class, event == 1
** Post-Conditions: if have 2 parents, give birth; if not, no birth
*********************************************************************/
void Zoo::delivery (int parents, int parentIndex) {
    int parentType;

    if (parents >= 2) {
        parentType = roster[parentIndex] -> getType ();
        cout << "Your " << announceType (parentType) << "s gave birth!" << endl << "You now have " << roster[parentIndex] -> getNumBabies () << " more " << announceType (parentType) << " baby/babies." << endl;

        for (int i = 0; i < (roster[parentIndex] -> getNumBabies ()); i++) {    
            if (capacity < (numAnimals + 100))
                expandCapacity (); 
            
            if (parentType == 0)
                roster[numAnimals] = new Monkey (0);
            else if (parentType == 1) 
                roster[numAnimals] = new Meerkat (0);
            else if (parentType == 2)
                roster[numAnimals] = new SeaOtter (0);

            numAnimals ++;
        }
    }

    else
        cout << "Birth!" << endl << "► Your animals cannot give birth since you do not have 2 adults of one type of animal." << endl;
}

/*********************************************************************
** Function: expandCapacity ()
** Description: expands the capacity of the zoo if the user could potentially exceed it in the next move
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: expands capacity by 103 (100 for 100 shop limit, 3 for 3 meerkat babies)
*********************************************************************/
void Zoo::expandCapacity () {
    capacity = capacity + 103;
    Animal** temp = new Animal* [capacity];

    for (int i = 0; i < capacity - 103; i++) {
        temp[i] = roster[i];
    }

    if (roster!= NULL) {
        delete[] roster;
    }

    roster = temp;
}

/*********************************************************************
** Function: shop ()
** Description: allows user to purchase up to 100 animals of one type per week
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: user can choose to purchase or not
*********************************************************************/
void Zoo::shop () {
    int purchase, type, numToPurchase, potentialPrice = 0;
    
    cout << "\u001b[1m[SHOP]\x1b[0m" << endl;
    cout << "► Would you like to purchase animals? (0-no, 1-yes): ";
    cin >> purchase;

    if (!(purchase == 0 || purchase == 1)) {
        do {
            cout << "  \u001b[31mPlease enter a valid number: \x1b[0m";
            cin >> purchase;
        } while (!(purchase == 0 || purchase == 1));
    }

    if (purchase == 1) {
        errorHandle (type, numToPurchase);
        verifyFunds (type, numToPurchase, potentialPrice);

        for (int i = 0; i < numToPurchase; i++)
            purchaseAnimal(type);
    }
}

/*********************************************************************
** Function: errorHandle (int&, int&)
** Description: error handles users input when purchasing animals
** Parameters: int& type, int& numToPurchase
** Pre-Conditions: Zoo class
** Post-Conditions: reprompts user if invalid int is inputted
*********************************************************************/
void Zoo::errorHandle (int& type, int& numToPurchase) {
    cout << "► What type of animal would you like to purchase? (0-monkey, 1-meerkat, 2-sea otter): ";
    cin >> type;

    if (!(type == 0 || type == 1 || type == 2)) {
        do {
            cout << "  \u001b[31mPlease enter a valid number: \x1b[0m";
            cin >> type;
        } while (!(type == 0 || type == 1 || type == 2));
    }

    cout << "► How many would you like to purchase? (purchase from 0 to 100): ";
    cin >> numToPurchase;

    if (!(numToPurchase >= 0 && numToPurchase <= 100)) {
        do {
            cout << "  \u001b[31mPlease enter a valid number: \x1b[0m";
            cin >> numToPurchase;
        } while (!(numToPurchase >= 0 && numToPurchase <= 100));
    }
}

/*********************************************************************
** Function: verifyFunds (int, int, int)
** Description: verifies that the user has enough money to go through with the suggest purchase
** Parameters: int type, int numToPurchase, int potentialPrice
** Pre-Conditions: Zoo class
** Post-Conditions: if enough money, purchase successful; if not, reprompt
*********************************************************************/
void Zoo::verifyFunds (int& type, int& numToPurchase, int& potentialPrice) {
    if (type == 0) 
        potentialPrice = 12000;
    else if (type == 1) 
        potentialPrice = 500;
    else if (type == 2) 
        potentialPrice = 4000;
    
    if (bankBalance <= potentialPrice * numToPurchase) {
        do {
            cout << "  \u001b[31mYou do not have enough money. Please enter a valid number: \x1b[0m";
            cin >> numToPurchase;
        } while (bankBalance <= potentialPrice * numToPurchase);
    }
}

/*********************************************************************
** Function: purchaseAnimal (int)
** Description: remakes the roster to have the newly purchase animal(s)
** Parameters: int type
** Pre-Conditions: Zoo class
** Post-Conditions: increments number of animals and adds the animal
*********************************************************************/
void Zoo::purchaseAnimal (int type) { 
    //check for funds
    if (capacity < (numAnimals + 100))
        expandCapacity ();
    
    if (type == 0) {
        roster[numAnimals] = new Monkey (twoYearOldAnimal);
    }
    else if (type == 1) {
        roster[numAnimals] = new Meerkat (twoYearOldAnimal);
    }
    else if (type == 2) {
        roster[numAnimals] = new SeaOtter (twoYearOldAnimal);
    }

    bankBalance = bankBalance - roster[numAnimals] -> getPrice ();  //subtract money from bank
    numAnimals ++;  //since bought an animal, increase number
}

/*********************************************************************
** Function: feedAnimals ()
** Description: automatically pays from the user's bank the amount of money needed for the zoo's weekly food
** Parameters: none
** Pre-Conditions: Zoo class
** Post-Conditions: if enough money, payment successful; if not, bankrupt
*********************************************************************/
void Zoo::feedAnimals () {
    double originalBalance = bankBalance;
    cout << endl << "\u001b[1m[FEEDING COSTS]\x1b[0m" << endl;

    for (int i = 0; i < numAnimals; i++) {
        bankBalance = bankBalance - roster[i] -> calculateFoodCost ();
    } 

    cout << "You spend $" << originalBalance - bankBalance << " on food for your animals." << endl;

    if (bankBalance <= 0) 
        bankrupt = 1;
}

/*********************************************************************
** Function: announceType (int)
** Description: converts int type to a string for readability
** Parameters: int type
** Pre-Conditions: Zoo class
** Post-Conditions: 0 = "monkey", 1 = "meerkat", 2 = "sea otter"
*********************************************************************/
string Zoo::announceType (int type) {
    if (type == 0) {
        return "monkey";
    }
    
    else if (type == 1) {
        return "meerkat";
    }

    else {
        return "sea otter";
    }
}