#include <getopt.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "trie.cpp"
#include "encoder.cpp"

enum State { NONE, COMPRESSION, DECOMPRESSION };
struct Options {
	State state;
	std::istream* input_stream;
	std::ostream* output_stream;
	Options(State _state, std::istream& input, std::ostream& output) :
			state(_state), input_stream(&input), output_stream(&output) {}
};

void print_help() {
	std::cerr << "Usage:\n";
	std::cerr << "Compression: ./lz78 -c <input_file> [-o <output_file>]\n";
	std::cerr << "Decompression: ./lz78 -x <input_file> [-o <output_file>]\n";
}

void print_whole_file(Options& options) {
	std::string line;
	std::cout << ":::\n";
	while (getline(*(options.input_stream), line)) {
		(*options.output_stream) << line << std::endl;
	}
}

int main(int argc, char** argv) {
	bool READING = true;
	State state = NONE;
	std::string input_file, output_file;
	std::ifstream input_stream;
	std::ofstream output_stream;

	Options options(state, std::cin, std::cout);

	while (READING) {
		// Reading Command Line Options and Parsing Them
		switch (getopt(argc, argv, "c:x:o:")) {
			case 'c':
				if (state != NONE) {
					std::cerr << "Error: Files for compression and decompression were given." << std::endl;
					print_help();
					return 1;
				}
				state = COMPRESSION;
				input_file = optarg;
				break;
			case 'x':
				if (state != NONE) {
					std::cerr << "Error: Files for compression and decompression were given." << std::endl;
					print_help();
					return 1;
				}
				state = DECOMPRESSION;
				input_file = optarg; 
				break;
			case 'o':
				output_file = optarg;
				break;
			default:
				READING = false;
				break;
		}
	}

	if (state == NONE) {
		print_help();
		return 1;
	}

	// Opening Files
	input_stream.open(input_file);
	if (!input_stream.is_open()) {
		std::cerr << "Error opening input file [" << input_file << "]\n";
		return 1;
	}
	options.input_stream = &input_stream;

	if (output_file != "") {
		output_stream.open(output_file);
		if (!output_stream.is_open()) {
			std::cerr << "Error opening output file [" << output_file << "]\n";
			return 1;
		}
		options.output_stream = &output_stream;
	}

	if (state == COMPRESSION) {
		std::string s(std::istreambuf_iterator<char>(input_stream), {});
		auto tokens = encode(s);
		for (auto [node, ch] : tokens) {
			output_stream.write((const char*)&node, sizeof(int));
			output_stream << ch;
		}
	} else { // DECOMPRESSION
		(*options.output_stream) << decode(input_stream);
	}

	return 0;
}
