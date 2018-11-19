#include "FLUKE287.h"

FLUKE287::FLUKE287(){

}

FLUKE287::~FLUKE287(){

}

std::string FLUKE287::getSigrokOut(){
	std::string cmd = "sigrok-cli --driver=fluke-dmm:conn=/devttyUSB0 -C P2 --samples 1"; 
	std::string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");
	
	if (stream) {
		while (!feof(stream))
		if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}

	return data; 
}

std::vector<std::string> FLUKE287::getSplitOut(){
	std::vector<std::string>data;
        const std::string cm = FLUKE287::getSigrokOut();
        std::stringstream steam(cm);
        std::string dat;
        char deli = ' ';
 
        while(std::getline(steam, dat, deli)){
                data.push_back(dat);
		//DEBUG
                //std::cout << dat << std::endl;
		//DEBUG
        }
	return data;
}

void FLUKE287::readValues(std::vector<std::string> dat){
	Amode		= false;
	Hold		= false;
	Relative	= false;
	cmode		= false;
	diodemode	= false;	


	for(int i = 2; i < dat.size(); i++){
		for(int j = 0; j < 14; j++){
			if (dat[i] == unit[j]){
				cunit = unit[j];
			}
		}
		
		if(dat[i] == mode[0]) Amode = true;
		else if(dat[i] == mode[1]) Hold = true;
		else if(dat[i] == mode[2]) Relative = true;
		else if(dat[i] == currentmode[0]) cmode = AC;
		else if(dat[i] == currentmode[1]) cmode = DC;
		else if(dat[i] == currentmode[2]) diodemode = false;
		
	}

	value = ::atof(dat[1].c_str());
	
	if(cunit == unit[0] || cunit == unit[1]){
		mmode = voltage;
		_mmode = "Voltage";
	}else if(cunit == unit[2] || cunit == unit[3]){
		mmode = frequency;
		_mmode = "Frequency & Dutycycle";
	}else if(cunit == unit[4] || cunit == unit[5] || cunit == unit[6]){
		mmode = resistance;
		_mmode = "Resistance";
	}else if(cunit == unit[7] || cunit == unit[8] || cunit == unit[9] || cunit == unit[10]){
		mmode = capacitance;
		_mmode = "Capacitance";
	}else if(cunit == unit[11] || cunit == unit[12] || cunit == unit[13]){
		mmode = current;
		_mmode = "Current";
	}else if(diodemode == true){
		mmode = diode;
		_mmode = "Diode";
	}

}

