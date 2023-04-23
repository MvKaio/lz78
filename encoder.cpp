#ifndef ENCODER_CPP
#define ENCODER_CPP

#include "trie.cpp"
#include <string>

using std::string, std::vector, std::pair;

vector<pair<int, char>> encode(string s) {
	Trie trie;
	int current_node = 0; // root

	s += '\0';

	vector<pair<int, char>> answer;

	for (int i = 0; i < s.size(); i++) {
		int next_node = trie.next_node(current_node, s[i]);
		if (next_node == -1) {
			trie.insert(current_node, s[i]);
			answer.emplace_back(current_node, s[i]);
			current_node = 0;
		} else {
			current_node = next_node;
		}
	}

	return answer;
}

string decode(std::istream& input) {
	Trie trie;
	string answer;

	int node;
	char new_char;
	for (int index = 1; input; index++) {
		input.read((char*)&node, 4);
		input.get(new_char);
		if (!input) break;
		std::cout << "[" << node << "." << new_char << "]" << std::endl;
		trie.insert(node, new_char);
		answer += trie.get_string(index);
		if (new_char == '\0')
			answer.pop_back();
	}

	return answer;
}

#endif
