#ifndef TRIE_CPP
#define TRIE_CPP

#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string;

// Dictionary Structure used by the compression algorithm
// Each node possesses an integer identifier `node`
// The root has identifier 0
// The user of the structure can, given a `node`, 
//   identify if it has a transition with a given character,
//   add this transition if it hasn't,
//   and recover the prefix string represented by that `node`
class Trie {
  private:
	struct Node {
		int parent; char last_char;
		vector<int> children;
		Node(int p=0, char c=0) : parent(p), last_char(c) {}
		inline void add_child(int index) {
			children.push_back(index);
		}
	};
	vector<Node> nodes;

  public:
	Trie() : nodes(1) {}
	// Returns the next identifier by following the transition
	// from `node` with `next_char`, or -1 if it doesn't exist
	int next_node(int node, char next_char) {
		for (int next : nodes[node].children) {
			if (nodes[next].last_char == next_char)
				return next;
		}
		return -1;
	}

	// Inserts the transition from `node` with `next_char`
	// For performance reasons, the existence of the transition is not checked
	void insert(int node, char next_char) {
		nodes.push_back(Node(node, next_char));
		nodes[node].add_child(nodes.size() - 1);
	}

	// Returns the prefix string represented by the `node`
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
