#include <getopt.h>
#include <iostream>
#include <fstream>
#include <string>
#include "encoder.cpp"

void print_help() {
	std::cerr << "Usage:\n";
	std::cerr << "Compression: ./lz78 -c <input_file> [-o <output_file>]\n";
	std::cerr << "Decompression: ./lz78 -x <input_file> [-o <output_file>]\n";
}

int main(int argc, char** argv) {
	// Reading Command Line Options and Parsing Them
	enum Mode { NONE, COMPRESSION, DECOMPRESSION };
	Mode mode = NONE;
	std::string input_file, output_file;
	std::ifstream input_stream;
	std::ofstream output_stream;

	bool READING = true;
	while (READING) {
		switch (getopt(argc, argv, "c:x:o:")) {
			case 'c':
				if (mode != NONE) {
					std::cerr << "Error: Files for compression and decompression were given." << std::endl;
					print_help();
					return 1;
				}
				mode = COMPRESSION;
				input_file = optarg;
				break;
			case 'x':
				if (mode != NONE) {
					std::cerr << "Error: Files for compression and decompression were given." << std::endl;
					print_help();
					return 1;
				}
				mode = DECOMPRESSION;
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

	if (mode == NONE) {
		print_help();
		return 1;
	}

	// Opening Files
	input_stream.open(input_file);
	if (!input_stream.is_open()) {
		std::cerr << "Error opening input file [" << input_file << "]\n";
		return 1;
	}

	if (output_file == "") {
		int dot_position = find(input_file.begin(), input_file.end(), '.') -
				input_file.begin();
		string extension = (mode == COMPRESSION ? ".z78" : ".txt");
		output_file = input_file.substr(0, dot_position) + extension;
	}

	output_stream.open(output_file);
	if (!output_stream.is_open()) {
		std::cerr << "Error opening output file [" << output_file << "]\n";
		return 1;
	}

	// Running the Compression or Decompression Method
	if (mode == COMPRESSION) {
		std::string s(std::istreambuf_iterator<char>(input_stream), {});
		auto tokens = encode(s);
		if (write_to_a_file(tokens, output_stream)) {
			std::cout << "Successfully saved the compressed file [" << output_file << "]\n";
		} else {
			std::cerr << "Error writing to the compressed file [" << output_file << "]\n";
			return 1;
		}
	} else { // DECOMPRESSION
		output_stream << decode(input_stream);
		std::cout << "Successfully saved the decompressed file [" << output_file << "]\n";
	}

	return 0;
}
