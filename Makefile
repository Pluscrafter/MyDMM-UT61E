VERSION		= 6.3.0
CXX		= /usr/bin/arm-linux-gueabihf-g++
CXXFLAGS	= -Ofast -Wall
INCLUDES	= -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/
LIBS		= -lsigrok
OBJ		=
CFILES		= *.cpp *.h

.PHONY: prog

prog: $(OBJ)
	$(CXX) -o UT61EFLUKEDMM $(CFLIES) $(OBJ) $(CXXFLAGS) $(INCLUDES) $(LIBS)
