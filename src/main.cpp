#include <iostream>
#include <fstream>
#include <chrono>
#include "UT61E.h"

int main(int argc, char **argv){
	std::cout << "Start program" << std::endl << "Connect device ..." << std::endl;
	UT61E ut;
	std::ofstream data;

	

	while(true){
		auto start = std::chrono::steady_clock::now();
		ut.getSigrokOut();
		ut.readValues(ut.getSplitOut());

		std::cout << ut.readTemp() << std::endl;
		auto stop = std::chrono::steady_clock::now();
		float time = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
		std::cout << time/1000 <<std::endl;
		data.open(argv[1], std::ofstream::app);
		data << time/1000 << "	" << ut.readTemp() << std::endl;
		data.close();
		

	}
	return 0;
}
