#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// printf("here0\n");
	int m1, n;
	scanf("%d%d", &m1, &n);
	int tmp;
	map<int, int> m;
	// printf("here1\n");
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m1; ++j) {
			scanf("%d", &tmp);
			// printf("here2\n");
			m[tmp] += 1;
		}
	}
	map<int, int>::iterator iter;
	int maxN = -1, result = 0;
	for(iter = m.begin(); iter != m.end(); ++iter) {
		if(iter->second > maxN) {
			result = iter->first;
			maxN = iter->second;
		}
	}
	printf("%d\n", result);
	return 0;
}