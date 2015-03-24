#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, p;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &N, &p);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if(tmp >= 1)
			v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	
	int result = -1;
	int M;
	for(int i = 0; i < v.size(); ++i) {
		M = v[i] * p;
		int cur;
		if(M < 0)
			cur = v.size() - i; 
		else
			cur = upper_bound(v.begin(), v.end(), M) - v.begin() - i;
		result = max(result, cur);
	}

	printf("%d\n", result);

	return 0;
}