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
	Date random;

	//Item * item;
///	item = new Item;
	//item->SetAll("MIlk", 6.09, 88, random, 89076);
	//cout << item->printItem();


////	float i;
////
////
//	 i =  6.46 + 33.70 + 19.55 + 199.59 + 50.80 ;
//	 cout << i << endl;
//	i =  i + (i * .0825);
//	 cout << i << endl;
//	 i = i - (i * .0825);
//	 cout << i << endl;

	test.readInMembers();
	test.readItems();
	//test.sortingItems(PRICE);
	//cout << test.getItemCount();
	//cin.ignore(1000, '\n');



	for(int i= 0; i < test.getMemCount(); i++ ){

		cout << test.PrintMember(i) << endl;
	}






//store.readIn();





	return 0;
}
