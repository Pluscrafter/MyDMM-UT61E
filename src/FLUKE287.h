#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define DC false
#define AC true

class FLUKE287{
public:
	FLUKE287();
	~FLUKE287();
	
	bool Amode      = false;
        bool Hold       = false;
        bool Relative   = false;
        bool cmode      = false;
        bool diodemode  = false;

        std::string cunit;
        std::string _mmode;

        double value;

	enum Mode{
                voltage, resistance, capacitance,current,diode,frequency
        };

        Mode mmode;
	
	
	std::string getSigrokOut();
	std::vector<std::string> getSplitOut();

	void readValues(std::vector<std::string>);
private:
	std::string unit[14] = {
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

	std::string mode[3] = {
		"AUTO",
		"HOLD",
		"REL"
	};
	std::string currentmode[3]{
		"AC",
		"DC",
		"DIODE"
	};
};

