#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned int uint;

int findCha(int i, const vector<int> &v) {
	if(i == v[i])
		return i;
	else
		return findCha(v[i], v);
}

void makeCha(vector<int> &v, vector<int> &rank) {
	for(uint i = 0; i < v.size(); ++i)
		v[i] = i;
	for(uint i = 0; i < rank.size(); ++i) 
		rank[i] = 0;
}

void unionCha(int i, int j, vector<int> &v, vector<int> &rank) {
	i = findCha(i, v);
	j = findCha(j, v);
	if(i == j)
		return;
	if(rank[i] > rank[j]) {
		v[j] = i;
	}
	else {
		v[i] = j;
		if(rank[i] == rank[j]) {
			++rank[j];
		}
	}
}

int main(int argc, char *argv[]) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	vector< pair<int, int> > path(M, pair<int, int>(0, 0));
	for(uint i = 0; i < path.size(); ++i) {
		scanf("%d%d", &(path[i].first), &(path[i].second));
	}
	vector<int> check(K, 0);
	for(uint i = 0; i < check.size(); ++i) {
		scanf("%d", &check[i]);
	}

	vector<int> rank(N+1, 0);
	vector<int> pre(N+1, 0);
	int target;
	for(uint i = 0; i < check.size(); ++i) {
		target = check[i];
		makeCha(pre, rank);
		for(uint j = 0; j < path.size(); ++j) {
			if(target == path[j].first || target == path[j].second)
				continue;
			unionCha(path[j].first, path[j].second, pre, rank);
		
		}
		vector<int> tmp(N+1, 0);
		for(uint j = 1; j <= N; ++j) {
			++tmp[findCha(j, pre)];
		}
		
		int count = 0;
		for(uint j = 1; j <= N; ++j) {
			if(0 != tmp[j])
				++count;
		}
		printf("%d\n", count-2);
		
	}
	
	return 0;
}
