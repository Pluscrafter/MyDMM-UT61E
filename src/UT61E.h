#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define DC false
#define AC true

class UT61E{
public:
	UT61E();
	~UT61E();
	
	std::string getSigrokOut();
	std::vector<std::string> getSplitOut();
private:
	std::string page0[14] = {
		"mV",
		"V",
		"Hz",
		"%",
		"Ω",
		"kΩ",
		"MΩ",
		"pF",
		"nF",
		"µF",
		"mF",
		"µA",
		"mA",
		"A"
	};

	std::string page1[6] = {
		"DC",
		"AC",
		"AUTO",
		"HOLD",
		"REL",
		"DIODE"
	};

	std::string page2[3]{
		"AUTO",
		"REL",
		"HOLD"
	};

	std::string page3[1]{
		"REL"
	};

	std::string page4[1]{
		"REL"
	};

	bool Automode 	= false;
	bool Hold	= false;
	bool Relative	= false;
	bool DAmode	= false;

};

