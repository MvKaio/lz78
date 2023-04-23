CXX = g++
CXXFLAGS = -O2 -std=c++17
SRC = ./src
SCRIPTS = ./scripts

all: $(SRC)/*
	$(CXX) $(CXXFLAGS) $(SRC)/lz78.cpp -o lz78

compress:
	$(SCRIPTS)/compress.sh

clean:
	rm lz78 && rm -r outputs
