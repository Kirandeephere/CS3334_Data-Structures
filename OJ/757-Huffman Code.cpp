/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237628
 * Submitted at:  2022-12-03 20:47:39
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    757
 * Problem Name:  Huffman Code
 */

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int freq, freqSum;
	Node* left, * right;

	Node(int freq) {
		this->freq = this->freqSum = freq;
		this->left = this->right = NULL;
	}

	Node(int freqSum, Node* left, Node* right) {
		this->freq = 0;
		this->freqSum = freqSum;
		this->left = left;
		this->right = right;
	}
};

class comparator {
public:
	bool operator()(Node* a, Node* b) { return a->freqSum > b->freqSum; }
};

class Tree {
public:
	Node* root = NULL;
	priority_queue<Node*, vector<Node*>, comparator> minHeap;
	int weightedLength = 0;

	void IT(int);
	void CT();
	void Counter(Node*, int);
};

void Tree::IT(int n) {
	for (int i = 0; i < n; ++i) {
		int freq;
		cin >> freq;
		minHeap.push(new Node(freq));
	}
	CT();
}

void Tree::CT() {
	while (minHeap.size() > 1) {
		Node* a = minHeap.top(); minHeap.pop();
		Node* b = minHeap.top(); minHeap.pop();

		minHeap.push(new Node(a->freqSum + b->freqSum, a, b));
	}

	this->root = minHeap.top();
	minHeap.pop();
}

void Tree::Counter(Node* node, int LCounter) {
	if (node->freq == node->freqSum)
		weightedLength += node->freq * LCounter;
	else {
		Counter(node->left, LCounter + 1);
		Counter(node->right, LCounter + 1);
	}
}

int main() {
	int n;
	while (cin>>n) {
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}

		Tree* tree = new Tree();
		
		tree->IT(n);
		tree->Counter(tree->root, 0);
		cout << tree->weightedLength << endl;

		delete tree;
	}

	return 0;
}