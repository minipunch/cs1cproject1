#include <iostream>
#include "executive.h"
#include "Store.h"

using namespace std;
/*
 * READ THIS!
 * This main is for testing only, it will not look like this in the qt project
 */
int main() {

	// stupid test program - 2/25/16 10:50 pm
	Store store;
	executive josh;
//	executive phil;

//	josh.setExprDate(3,3,2015);
//	josh.printMember();
//	phil.setRebateAmount(200);
//	phil.printExecutive();
//
	Date poop;
//	string test = "02/06/2015";
//	poop = store.ConvertDate(test);
//	cout << poop.DisplayDate();



store.readIn();

for(int i = 0; i < store.getMemCount(); i++){
	cout << store.PrintMember(i);
}





//store.readIn();





	return 0;
}
