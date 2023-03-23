EXENAME = ana

OBJS = main.o MyAna.o mppcjp.o 

AR            = g++
CXX           = g++ 
ROOTINCS      = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --glibs)
CXXFLAGS      = -g -Wall -fPIC $(ROOTINCS)
SOFLAGS       = -shared

all: $(OBJS)
	$(CXX) -o $(EXENAME) $(OBJS) $(ROOTLIBS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXENAME) *~

