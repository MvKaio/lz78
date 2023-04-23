CXX = g++
CXXFLAGS = -O2 -std=c++17
SRC = ./src
SCRIPTS = ./scripts

all, lz78: $(SRC)/*
	$(CXX) $(CXXFLAGS) $(SRC)/lz78.cpp -o lz78

compress: lz78
	$(SCRIPTS)/compress.sh

check: lz78
	$(SCRIPTS)/check.sh

collect: lz78
	$(SCRIPTS)/collect.sh

clean:
	rm lz78 && rm -r outputs
