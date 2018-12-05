#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include "UT61E.h"

int main(int argc, char **argv){
	std::cout << "Start program" << std::endl << "Connect device ..." << std::endl;
	UT61E ut;
	std::ofstream data;
	std::ofstream gnudata;	

	data.open(argv[1], std::ofstream::app);
	data << "dTime [s]" << ";" << "measTemp [°C]"  << ";" << "calcTemp [°C]" << std::endl;
 	data.close();

	int initTemp;
	int roomTemp = atoi(argv[3]);  
	float etime = 0;

	std::cout << "Room temperature: " << roomTemp << std::endl;

	for(int i = 0; i<5;i++){
		ut.getSigrokOut();
                ut.readValues(ut.getSplitOut());

                initTemp =  ut.readTemp();
		std::cout << ut.readTemp() << std::endl;
	}

	std::cout << "Start temperature: " << initTemp << std::endl;

	int c = initTemp-roomTemp;

	std::cout << "c: " << c << std::endl;

	while(true){
		auto start = std::chrono::steady_clock::now();
		ut.getSigrokOut();
		ut.readValues(ut.getSplitOut());

		std::cout << "Meausred temperature:    " << ut.readTemp() << std::endl;
		auto stop = std::chrono::steady_clock::now();
		float time = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();

		float calcTemp = roomTemp + pow(c*M_E,-(etime/1000));
		std::cout << "Caluculated temperature: " <<calcTemp << std::endl;

		std::cout << "Elapsed time:            " << etime/1000 <<std::endl;

		etime += time;

		data.open(argv[1], std::ofstream::app);
		data << etime/1000 << ";" << ut.readTemp() << ";" << calcTemp << std::endl;
		data.close();

		gnudata.open(argv[2], std::ofstream::app);
                gnudata << etime/1000 << "	" << ut.readTemp() << "		" << calcTemp << std::endl;
                gnudata.close();
		

	}
	return 0;
}
