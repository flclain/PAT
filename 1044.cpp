#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Pay{
public:
	int lhs;
	int rhs;
	int sum;
	bool operator < (const Pay &a) const {
		return lhs < a.lhs;
	}
};
//
//bool cmp(const Pay &i, const Pay &j) {
//	return i.lhs < j.lhs;
//}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> v(N, 0);
	for(int i = 0; i < N; ++i)
		scanf("%d", &v[i]);
	if(N <= 0)
		return 0;
	vector<Pay> result;
	for(int i = 0; i < N; ++i) {
		bool isSmall = true;
		Pay tmp;
		int sum = 0;
		for(int j = i; j < N; ++j) {
			if(!isSmall)
				break;
			sum += v[j];
			if(sum >= M) {
				tmp.lhs = i + 1;
				tmp.rhs = j + 1;
				tmp.sum = sum - M;
				result.push_back(tmp);
				isSmall = false;
			}

		}
		if(isSmall)
			break;
	}
	
	if(0 == result.size())
		return 0;
	int gap = result[0].sum;
	for(int i = 0; i < result.size(); ++i) {
		if(result[i].sum < gap)
			gap = result[i].sum;
	}
	vector<Pay> f;
	for(int i = 0; i < result.size(); ++i) {
		if(gap == result[i].sum)
			f.push_back(result[i]);
	}
	
	sort(f.begin(), f.end());

	for(int i = 0; i < f.size(); ++i)
		printf("%d-%d\n", f[i].lhs, f[i].rhs);

	return 0;
}