CXX = g++
CXXFLAGS = -O2 -std=c++17
SRC_FOLDER = ./src/

all:
	$(CXX) $(CXXFLAGS) $(SRC_FOLDER)lz78.cpp -o lz78

clean:
	rm lz78
