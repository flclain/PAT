#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int val;
	node *left;
	node *right;
};

node* returnRoot(const vector<int> &poOrd, const vector<int> &inOrd, int poLeft, int poRight, int inLeft, int inRight) {
	// cout << poLeft << " " << poRight << " " << inLeft << " " << inRight << endl;
	if(poRight < poLeft || inRight < inLeft || poRight - poLeft != inRight - inLeft) {
		return NULL;
	}
	node *root = new node;
	root->val = poOrd[ poRight ];
	int rootPos = 0, i = inLeft;
	for(; i <= inRight; ++i) {
		if(inOrd[i] == root->val)
			break;
	}
	if(i > inRight) {
		delete root;
		return NULL;
	}
	rootPos = i;
	int rightNum = inRight - rootPos, leftNum = rootPos - inLeft;
	root->left = returnRoot(poOrd, inOrd, poLeft, poLeft + leftNum - 1, inLeft, inLeft + leftNum - 1);
	root->right = returnRoot(poOrd, inOrd, poLeft + leftNum, poRight - 1, inLeft + leftNum + 1, inRight);
	return root;

}

void levelOrder(node *root) {
	if(NULL == root)
		return;
	vector<int> v;
	queue<node*> q;
	q.push(root);
	while(q.size() != 0) {
		if(q.front()->left != NULL)
			q.push(q.front()->left);
		if(q.front()->right != NULL)
			q.push(q.front()->right);
		v.push_back(q.front()->val);
		q.pop();
	}
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); ++i) {
		printf(" %d", v[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	if(n <= 0) {
		return 0;
	}
	vector<int> poOrd(n, 0);
	vector<int> inOrd(n, 0);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &poOrd[i]);
	}
	for(int i = 0; i < n; ++i)
		scanf("%d", &inOrd[i]);

	int poRight = poOrd.size(), inRight = inOrd.size();

	node *root = returnRoot(poOrd, inOrd, 0, poRight-1, 0, inRight-1);
	// printf("%d\n", root->val);
	levelOrder(root);

	return 0;
}
