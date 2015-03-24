#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>

using namespace std;

struct record
{
	int sum;
	int startIndex;
	int endIndex;
	/* data */
};

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	record maxSum;
	maxSum.sum = -1;
	record tmp;
	tmp.sum = -1;
	tmp.startIndex = 0;
	for(int i = 0; i < n; ++i) {
		if(-1 == tmp.sum && v[i] < 0) {
			tmp.startIndex = i + 1;
			continue;
		}
		else if(-1 == tmp.sum && v[i] >= 0) {
			tmp.sum = 0;
			tmp.startIndex = i;
		}
		tmp.endIndex = i;
		tmp.sum += v[i];
		if(tmp.sum > maxSum.sum) {
			maxSum.sum = tmp.sum;
			maxSum.startIndex = tmp.startIndex;
			maxSum.endIndex = tmp.endIndex;
		}
		else if(tmp.sum < 0) {
			tmp.sum = -1;
			tmp.startIndex = i+1;
		}
	}
	if(maxSum.sum < 0)
		printf("0 %d %d\n", v[0], v[n-1]);
	else
		printf("%d %d %d\n", maxSum.sum, v[maxSum.startIndex], v[maxSum.endIndex]);
	return 0;
}