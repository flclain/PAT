#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int _val;
	int _num;
};

int main(int argc, char*argv[]) {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> favor(M, 0);
	vector<int> inFavor(N+1, 0);
	int tmp;
	for(int i = 0; i < M; ++i) {
		scanf("%d", &tmp);
		inFavor[tmp] = 1;
		favor[i] = tmp;
	}
	vector<int> stripe;
	int num;
	scanf("%d", &num);
	for(int i = 0; i < num; ++i) {
		scanf("%d", &tmp);
		if(1 == inFavor[tmp]) {
			stripe.push_back(tmp);
		}
	}

	if(0 == stripe.size() || 0 == favor.size()) {
		printf("0\n");
		return 0;
	}

	Node node;
	node._val = stripe[0];
	node._num = 0;
	vector<Node> stripes;
	for(int i = 0; i < stripe.size(); ++i) {
		if(stripe[i] == node._val) {
			node._num += 1;
		}
		else {
			stripes.push_back(node);
			node._val = stripe[i];
			node._num = 1;
		}
	}
	stripes.push_back(node);

	vector<int> replaceTable(N+1, 0);
	for(int i = 0; i < favor.size(); ++i) {
		replaceTable[ favor[i] ] = i;
	}

	for(int i = 0; i < stripes.size(); ++i)
		stripes[i]._val = replaceTable[ stripes[i]._val ];

	vector<int> f(stripes.size(), 0);
	f[0] = stripes[0]._num;
	for(int i = 1; i < stripes.size(); ++i) {
		f[i] = stripes[i]._num;
		for(int j = 0; j < i; ++j) {
			if(stripes[j]._val <= stripes[i]._val)
				f[i] = max(f[i], f[j] + stripes[i]._num);
		}
	}

	int maxLen = f[0];
	for(int i = 0; i < f.size(); ++i)
		if(f[i] > maxLen)
			maxLen = f[i];

	printf("%d\n", maxLen);

	// int maxLen = 0, curLen = 0, curS = 0, curF = 0;
	// dfs(stripes, favor, maxLen, curLen, curS, curF, remain);
	// printf("%d\n", maxLen);
	return 0;
}