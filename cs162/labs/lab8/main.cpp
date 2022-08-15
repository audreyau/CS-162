/*
	Written by Justin Goins as a lab demo that illustrates the impact of 
	computational complexity.
*/

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
	cout << "Duration (in microseconds) for part 1: " << duration.count() << endl;
	
	// now write code which will insert num Meerkats into list2.
	// the difference is that this code needs to insert each Meerkat
	// at the END of the forward_list
	forward_list<Meerkat> list2;
	
	// Track the time for this approach...
	start = high_resolution_clock::now();
	// add the first meerkat as a special case (since the list is currently empty)
	Meerkat mk1("Timon");
	list2.push_front(mk1);
	
	// Now we can add the remaining Meerkats
	for (unsigned long int i = 0; i < (num - 1); i++) {
		// The plan is to iterate over all the items until we reach the end.
		// We can then insert the new object.
		forward_list<Meerkat>::iterator it = list2.begin(); // it refers to the very first meerkat
		forward_list<Meerkat>::iterator next = list2.begin();
		while (1) {
			next++; // we use "next" as an iterator that points 1 item in front of "it"
			// Note from the documentation:
			// list2.end() returns an iterator referring to the past-the-end element.
			if (next == list2.end()) {
				// we are at the end of the list
				// let's insert our meerkat!
				Meerkat tmp("Anonymous Meerkat");
				list2.insert_after(it, tmp);
				break; // exit the while loop
			}
			it++;
		}
	}
	stop = high_resolution_clock::now();
	// compute the elapsed time in microseconds
	duration = duration_cast<microseconds>(stop - start);
	cout << "Duration (in microseconds) for part 2: " << duration.count() << endl;
	
	return 0;
}








