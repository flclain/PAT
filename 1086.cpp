#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

class Node{
public:
	int val;
	Node *left;
	Node *right;

	Node(int a):val(a), left(NULL), right(NULL) {};

};

class Action{
public:
	bool in;
	int val;
};

Node* returnRoot(vector<Action> &v, int up, int down) {
	if(down - up == 1) {
		Node *root = new Node(v[up].val);
		return root;
	}
	if(down - up < 1) {
		return NULL;
	}
	int i = up;
	// stack<int> s;
	int num = 0;
	for(; i <= down; ++i) {
		if(v[i].in) {
			++num;
		}
		else {
			--num;
		}
		if(0 == num)
			break;
	}
	Node *root = new Node(v[up].val);
	root->left = returnRoot(v, up+1, i-1);
	root->right = returnRoot(v, i+1, down);
	return root;
}

void printTree(Node *root, vector<int> &v) {
	if(NULL == root)
		return;
	printTree(root->left, v);
	printTree(root->right, v);
	v.push_back(root->val);
}

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	string tmp;
	vector<Action> v;
	
	int i = 0;

	while(cin >> tmp) {
		Action act;
		if(tmp == "Push") {
			act.in = true;
			cin >> act.val;
		}
		else {
			act.in = false;
		}
		v.push_back(act);
	}
	if(0 == N)
		return 0;
	int up = 0, down = v.size()-1;
	Node *root = returnRoot(v, up, down);
	vector<int> result;
	printTree(root, result);
	if(result.size() != 0)
		printf("%d", result[0]);
	for(int i = 1; i < result.size(); ++i)
		printf(" %d", result[i]);
	printf("\n");

	return 0;
}