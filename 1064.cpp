#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int f[20];

struct node {
	int val;
	node *left;
	node *right;
};

int getRootPos(int n) {
	if(0 == n)
		return 0;
	if(1 == n)
		return 1;
		
	int height = 0;
	int i = 0;
	for(; i < 20; ++i) {
		if(n < f[i])
			break;
	}
	height = i;
	int remain = min( n - f[height - 1], (f[height] - f[height-1]) / 2 );
	return (f[height - 1] - 1) / 2 + remain + 1;
}

node* getResult(const vector<int> &v, int startPos, int endPos) {
	int n = endPos - startPos + 1;
	if(n <= 0)
		return NULL;
	int rootPos = getRootPos(n);
	node* root = new node();
	root->val = v[ startPos + rootPos -1 ];
	root->left = getResult(v, startPos, startPos + rootPos - 2);
	root->right = getResult(v, startPos + rootPos, endPos);
	return root;
}

void printTree(node *root) {
	if(root == NULL)
		return;
	queue<node *> q;
	vector<int> v;
	q.push(root);
	while(q.size() != 0) {
		v.push_back(q.front()->val);
		if(NULL != q.front()->left)
			q.push(q.front()->left);
		if(NULL != q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); ++i) {
		printf(" %d", v[i]);
	}
	printf("\n");
}

int main(int argc, char *agrv[]) {
	// 2 pow
	int base = 1;
	for(int i = 0; i < 20; ++i) {
		f[i] = base;
		base *= 2;
	}
	for(int i = 1; i < 20; ++i) {
		f[i] += f[i-1];
	}
	
	// get input
	int n;
	scanf("%d", &n);
	if(0 == n)
		return 0;
		
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	
	// 
	sort(v.begin(), v.end());
	vector<int> result;
	node *root = getResult(v, 0, v.size()-1);
	
	// print result;
	printTree(root);

	return 0;
}