#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAXTABLE = 10;

int returnRoot( vector<int> &v) {
	if(v.size() == 1)
		return v[0];
	if(v.size() <= 0)
		return 0;

	sort(v.begin(), v.end());

	vector<int> f(MAXTABLE, 0);
	int base = 2;
	f[0] = 1;
	for(int i = 1; i < f.size(); ++i, base *= 2)  
		f[i] += f[i-1] + base;

	// for(int i = 0; i < f.size(); ++i)
	// 	printf("%d ", f[i]);
	
	int height = 0, n = v.size();
	for(; height < f.size(); ++height) {
		if(f[height] >= n)
			break;
	}
	int remain = n - f[height-1];
	int before = min( (f[height] - f[height-1]) / 2,  remain);
	return v[ before + (f[height-1] - 1) / 2 ];
}

int main(int argc, char* argv[]) {
	int N;
	scanf("%d", &N);
	vector<int> v(N, 0);
	for(int i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
	}
	printf("%d\n", returnRoot(v));

	return 0;
}