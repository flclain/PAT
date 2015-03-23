#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Node{
public:
	int adr;
	int val;
};

int nexts[100000];
int values[100000];
vector<Node> v;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int root, N, K;
	scanf("%d%d%d", &root, &N, &K);
	for(int i = 0; i < N; ++i) {
		int cur, val, tmpNext;
		scanf("%d%d%d", &cur, &val, &tmpNext);
		nexts[cur] = tmpNext;
		values[cur] = val;
	}
	int cur = root;
	
	while(-1 != cur) {
		Node tmp;
		tmp.adr = cur;
		tmp.val = values[cur];
		v.push_back(tmp);
		cur = nexts[cur];
	}
	for(int i = 0; i < v.size(); i += K) {
		if(i + K - 1 > v.size() - 1) {
			for(int j = i; j < v.size() - 1; ++j)
				printf("%05d %d %05d\n", v[j].adr, v[j].val, v[j+1].adr);
			printf("%05d %d -1\n", v[v.size() - 1].adr, v[v.size() - 1].val);
		}
		else if(i + K - 1 == v.size() - 1) {
			for(int j = v.size() - 1; j > i; --j) {
				printf("%05d %d %05d\n", v[j].adr, v[j].val, v[j-1].adr);
			}
			printf("%05d %d -1\n", v[i].adr, v[i].val);
		}
		else {
			for(int j = i + K - 1; j > i; --j) {
				printf("%05d %d %05d\n", v[j].adr, v[j].val, v[j-1].adr);
			}
			if(i + 2 * K - 1 <= v.size() - 1)
				printf("%05d %d %05d\n", v[i].adr, v[i].val, v[i + 2 * K - 1].adr);
			else
				printf("%05d %d %05d\n", v[i].adr, v[i].val, v[i + K].adr);
		}
	}

	return 0;
}