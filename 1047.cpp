#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector< vector<string> > v;
vector<string> names;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int N, K;
	scanf("%d%d", &N, &K);
	for(int i = 0; i < K; ++i) {
		vector<string> tmp;
		v.push_back(tmp);
	}
	for(int i = 0; i < N; ++i) {
		string name;
		int n, course;
		cin >> name >> n;
		names.push_back(name);
		for(int j = 0; j < n; ++j) {
			cin >> course;
			v[course - 1].push_back(name);
		}
	}
	for(int i = 0; i < K; ++i) {
		if(0 != v[i].size())
			sort(v[i].begin(), v[i].end());
		printf("%d %d\n", i + 1, v[i].size());
		for(int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j];
			printf("\n");
		}
	}

	return 0;
}