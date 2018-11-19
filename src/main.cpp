#include <iostream>
#include "UT61E.h"

int main(){
	std::cout << "Start program" << std::endl << "Connect device ..." << std::endl;
	UT61E ut;

	while(true){
		ut.getSigrokOut();
		ut.readValues(ut.getSplitOut());

		std::cout << ut._mmode << std::endl
			  << ut.value << " " << ut.cunit << " " << ut.cmode << std::endl;

	}
	return 0;
}
