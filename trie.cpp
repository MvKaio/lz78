#ifndef TRIE_CPP
#define TRIE_CPP

#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string;

struct Trie {
	struct Node {
		int parent; char last_char;
		vector<int> children;
		Node(int p=0, char c=0) : parent(p), last_char(c) {}
		inline void add_child(int index) {
			children.push_back(index);
		}
	};
	vector<Node> nodes;

	Trie() : nodes(1) {}
	int next_node(int node, char next_char) {
		for (int next : nodes[node].children) {
			if (nodes[next].last_char == next_char)
				return next;
		}
		return -1;
	}
	void insert(int node, char next_char) {
		nodes.push_back(Node(node, next_char));
		nodes[node].add_child(nodes.size() - 1);
	}
	string get_string(int node) {
		string answer;
		while (node > 0) {
			answer += nodes[node].last_char;
			node = nodes[node].parent;
		}
		std::reverse(answer.begin(), answer.end());
		return answer;
	}
};

#endif
