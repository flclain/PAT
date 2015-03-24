#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
	int i = 0;
	for(; i < lhs.size() && i < rhs.size(); ++i) {
		if(lhs[i] != rhs[i])
			return lhs[i] > rhs[i];
	}
	if(i == lhs.size() || i == rhs.size())
		return lhs.size() > rhs.size();
}

int main(int argc, char* argv[]) {
	int N, M, S;
	scanf("%d%d%d", &N, &M, &S);
	vector<int> weight(N, 0);
	for(int i = 0; i < N; ++i)
		scanf("%d", &weight[i]);
	vector<int> pre(N, 0);
	vector<int> isLeaf(N, 1);
	for(int i = 0; i < M; ++i) {
		int preNode, k;
		scanf("%d%d", &preNode, &k);
		isLeaf[preNode] = 0;
		int curNode;
		for(int j = 0; j < k; ++j) {
			scanf("%d", &curNode);
			pre[curNode] = preNode;
		}
	}
	vector< vector<int> > paths;
	for(int i = 0; i < N; ++i) {
		if(0 == isLeaf[i])
			continue;
		int cur = i, sum = 0;
		bool cut = false;
		vector<int> path;
		path.clear();
		while(cur != pre[cur]) {
			sum += weight[cur];
			path.push_back(weight[cur]);
			cur = pre[cur];
			if(sum > S) {
				cut = true;
				break;
			}
		}
		if(false == cut && sum + weight[cur] == S) {
			path.push_back(weight[cur]);
			reverse(path.begin(), path.end());
			paths.push_back(path);
		}
	}

	sort(paths.begin(), paths.end(), cmp);

	for(int i = 0; i < paths.size(); ++i) {
		printf("%d", paths[i][0]);
		for(int j = 1; j < paths[i].size(); ++j) {
			printf(" %d", paths[i][j]);
		}
		printf("\n");
	}

	return 0;
}