#include "UT61E.h"

UT61E::UT61E(){

}

UT61E::~UT61E(){

}

std::string UT61E::getSigrokOut(){
	std::string cmd = "sigrok-cli --driver=uni-t-ut61e:conn=1a86.e008 --samples 1"; 
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

std::vector<std::string> UT61E::getSplitOut(){
	std::vector<std::string>data;
        const std::string cm = UT61E::getSigrokOut();
        std::stringstream steam(cm);
        std::string dat;
        char deli = ' ';
 
        while(std::getline(steam, dat, deli)){
                data.push_back(dat);
                std::cout << dat << std::endl;
        }
	return data;
}

