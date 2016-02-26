#include <iostream>
#include "executive.h"
using namespace std;

int main() {

	// stupid test program - 2/25/16 10:50 pm

	member josh;
	executive phil;

	josh.printMember();
	josh.setExprDate(3,3,2015);
	josh.printMember();
	phil.setRebateAmount(200);
	phil.printExecutive();




	return 0;
}
