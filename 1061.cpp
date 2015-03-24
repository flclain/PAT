#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int tmp, tmpN;
	vector<vector<int> > v;
	for(int i = 0; i < n; ++i) {
		vector<int> s;
		scanf("%d", &tmpN);
		for(int j = 0; j < tmpN; ++j) {
			scanf("%d", &tmp);
			s.push_back(tmp);
		}
		sort(s.begin(), s.end());
		vector<int>::iterator iter = unique(s.begin(), s.end());
		s.erase(iter, s.end());
		v.push_back(s);
	}
	scanf("%d", &n);
	int a, b;
	double result;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		int maxSize = v[a-1].size() + v[b-1].size();
		vector<int> v1(maxSize, -1);
		vector<int> v2(maxSize, -1);
		vector<int>::iterator it1;
		vector<int>::iterator it2;
		it1 = set_union(v[a-1].begin(), v[a-1].end(), v[b-1].begin(), v[b-1].end(), v1.begin());
		it2 = set_intersection(v[a-1].begin(), v[a-1].end(), v[b-1].begin(), v[b-1].end(), v2.begin());
		result = 100.0 * (it2 - v2.begin()) / (it1 - v1.begin());
		printf("%.1f%%\n", result);
//		cout << (v2.end() - it2) << " " << (v1.end() - it1) << endl;
	}

	return 0;
}