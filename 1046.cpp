#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 1; i < n; ++i) {
		scanf("%d", &v[i]);
		v[i] += v[i-1];
	}
	int total;
	scanf("%d", &total);
	total += v[n-1];

	scanf("%d", &n);
	int a, b;
	int tmp;

	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		if(a > b)
			swap(a, b);
		tmp = v[b-1] - v[a-1];
		// printf("%d %d\n", v[a-1], v[b-1]);
		tmp = min(tmp, total - tmp);
		printf("%d\n", tmp);
	}

	return 0;
}