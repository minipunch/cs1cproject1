#include <iostream>
#include "executive.h"
#include "Store.h"

using namespace std;
/*
 * READ THIS!
 * This main is for testing only, it will not look like this in the qt project
 */
int main() {

	Store test;


	test.readItems();

	cout << test.getItemCount();
	cin.ignore(1000, '\n');

	for(int i= 0; i < test.getItemCount(); i++ ){

		cout << test.PrintItem(i) << endl;
	}






//store.readIn();





	return 0;
}
