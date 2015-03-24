#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXNUM = 1001;
const int MAXPLUS = 2001;

int main(int argc, char const *argv[])
{
	vector<double> v1(MAXNUM, 0);
	vector<double> v2(MAXNUM, 0);
	vector<double> result(MAXPLUS, 0);
	int n, nk;
	double ak;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%lf", &nk, &ak);
		v1[nk] = ak;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%lf", &nk, &ak);
		v2[nk] = ak;
	}

	for(int i = 0; i < MAXNUM; ++i) {
		for(int j = 0; j < MAXNUM; ++j) {
			if(0 == v1[i] || 0 == v2[j])
				continue;
			result[i+j] += v1[i] * v2[j]; 
		}
	}
	int total = 0;
	for(int i = 0; i < MAXPLUS; ++i) {
		if(0 != result[i]) {
			++total;
		}
	}
	printf("%d", total);
	for(int i = MAXPLUS-1; i >= 0; --i) {
		if(0 != result[i]) {
			printf(" %d %.1f", i, result[i]);
		}
	}
	printf("\n");

	return 0;
}