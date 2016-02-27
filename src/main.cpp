#include <iostream>
#include "executive.h"
#include "Store.h"

using namespace std;

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





	josh.setAll("Josh", "Regular", 12345, 69000, poop, .035);
	cout << josh.printMember();




//store.readIn();





	return 0;
}
