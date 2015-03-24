#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef vector<int>::iterator Iter;

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* returnRoot1(Iter lhs, Iter rhs, bool &isVal) {
	if(lhs >= rhs)
		return NULL;
	Node* root = new Node;
	root->val = *lhs;
	Iter it = lhs + 1;
	for(; it != rhs; ++it) {
		if(*it >= *lhs)
			break;
	}
	Iter breakPos = it;
	for(; it != rhs; ++it) {
		if(*it < *lhs) {
			isVal = false;
			delete root;
			return NULL;
		}
	}
	root->left = returnRoot1(lhs+1, breakPos, isVal);
	root->right = returnRoot1(breakPos, rhs, isVal);
	return root;
}

Node* returnRoot2(Iter lhs, Iter rhs, bool &isVal) {
	if(lhs >= rhs)
		return NULL;
	Node* root = new Node;
	root->val = *lhs;
	Iter it = lhs + 1;
	for(; it != rhs; ++it) {
		if(*it < *lhs)
			break;
	}
	Iter breakPos = it;
	for(; it != rhs; ++it) {
		if(*it >= *lhs) {
			isVal = false;
			delete root;
			return NULL;
		}
	}
	root->left = returnRoot2(lhs+1, breakPos, isVal);
	root->right = returnRoot2(breakPos, rhs, isVal);
	return root;
}

void printPos(Node *root, vector<int> &v) {
	if(root == NULL)
		return;
	printPos(root->left, v);
	printPos(root->right, v);
	v.push_back(root->val);
}

void printfV(const vector<int> &v) {
	if(v.size() == 0)
		return;
	printf("YES\n");
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); ++i)
		printf(" %d", v[i]);
	printf("\n");
}

int main(int argc, char*argv[]) {
	int N;
	scanf("%d", &N);
	vector<int> ori(N, 0);
	for(int i = 0; i < N; ++i)
		scanf("%d", &ori[i]);
	if(0 == N) {
		printf("NO\n");
		return 0;
	}

	bool isBST = true;
	Node* root1 = returnRoot1(ori.begin(), ori.end(), isBST);

	if(isBST) {
		vector<int> v;
		printPos(root1, v);
		printfV(v);
	}
	else {
		bool isM = true;
		Node *root2 = returnRoot2(ori.begin(), ori.end(), isM);
		if(isM) {
			vector<int> v;
			printPos(root2, v);
			printfV(v);
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}