#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// bingcha
vector<int> pre;
vector<int> num;
vector< vector<int> > link;
queue<int> q;

int find(int a) {
	while(pre[a] != a) 
		a = pre[a];
	return a;
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(num[a] > num[b]) {
		pre[b] = a;
	}
	else {
		pre[a] = pre[b];
		num[b]++;
	}
}

int main(int argc, char *agrv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		pre.push_back(i);
		num.push_back(1);
		link.push_back(vector<int>());
	}
	
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		link[a].push_back(b);
		link[b].push_back(a);
		join(a, b);
	}

	// "Error: K components"
	set<int> s;
	for(int i = 0; i < N; ++i) {
		s.insert(pre[i]);
	}
	if(1 != s.size()) {
		printf("Error: %d components\n", s.size());
		return 0;
	}

	// find the deepest root
	vector<int> deep(N, 0);
	for(int i = 0; i < N; ++i) {
		vector<bool> visited(N, false);
		q.push(i);
		q.push(-1);
		int curDeep = 0;
		while(!q.empty()) {
			int curNode = q.front();
			if(-1 != curNode)
				visited[curNode] = true;
			q.pop();
			if(-1 == curNode) {
				if(!q.empty()) {
					q.push(-1);
					++curDeep;
				}
			}
			else {
				for(int j = 0; j < link[curNode].size(); ++j) {
					if( !visited[ link[curNode][j] ] ) {
						q.push( link[curNode][j] );
						visited[ link[curNode][j] ] = true;
					}
				}
			}
		}
		deep[i] = curDeep;
	}

	int maxDeep = -1;
	for(int i = 0; i < deep.size(); ++i) {
		maxDeep = max(maxDeep, deep[i]);
	}
	for(int i = 0; i < deep.size(); ++i) {
		if(maxDeep == deep[i])
			printf("%d\n", i + 1);
	}

	return 0;
}