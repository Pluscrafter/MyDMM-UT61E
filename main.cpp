#include <iostream>
#include "UT61E.h"

int main(){
	std::cout << "Start program" << std::endl << "Connect device ..." << std::endl;
	UT61E ut;


	std::cout << ut.getSigrokOut()<< std::endl;
	ut.getSplitOut();	

	return 0;
}
