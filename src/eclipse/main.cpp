#include <iostream>
#include "executive.h"
#include "Store.h"

using namespace std;
/*
 * READ THIS!
 * This main is for testing only, it will not look like this in the qt project
 */
int main() {

	Date temp;
	Item *test;
	test = new Item;


	test->SetAll("Dvd", 13.37, 5, temp, 12345);
	cout << test->printItem();





//store.readIn();





	return 0;
}
