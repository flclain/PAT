#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Test {
public:
	string _id;
	int _score;
	int _finalRank;
	int _location;
	int _localRank;
};

bool cmp(const Test &rhs, const Test &lhs) {
	if(rhs._score != lhs._score)
		return rhs._score > lhs._score;
	else
		return rhs._id < lhs._id;
}

int main(int argc, char*argv[]) {
	int N;
	scanf("%d", &N);
	vector< vector<Test> > all;
	for(int i = 0; i < N; ++i) {
		int M;
		scanf("%d", &M);
		Test tmp;
		tmp._location = i + 1;
		vector<Test> a;
		for(int j = 0; j < M; ++j) { 
			cin >> tmp._id >> tmp._score;
			a.push_back(tmp);
		}
		all.push_back(a);
	}
	
	vector<Test> result;
	for(int i = 0; i < N; ++i) {
		if(0 == all[i].size())
			continue;
		sort(all[i].begin(), all[i].end(), cmp);
		int curRank = 1, curSore = all[i][0]._score, curNum = 0;
		for(int j = 0; j < all[i].size(); ++j) {
			if(all[i][j]._score == curSore) {
				all[i][j]._localRank = curRank;
				++curNum;
			}
			else {
				curRank += curNum;
				curNum = 1;
				all[i][j]._localRank = curRank; 
				curSore = all[i][j]._score;
			}
			result.push_back(all[i][j]);
		}
	}
	printf("%d\n", result.size());
	sort(result.begin(), result.end(), cmp);
	int curRank = 1, curSore = result[0]._score, curNum = 0;
	for(int i = 0; i < result.size(); ++i ) {
		if(result[i]._score == curSore) {
			result[i]._finalRank = curRank;
			++curNum;
		}
		else {
			curRank += curNum;
			curNum = 1;
			result[i]._finalRank = curRank;
			curSore = result[i]._score;
		}
		cout << result[i]._id;
		printf(" %d %d %d\n", result[i]._finalRank, result[i]._location, result[i]._localRank);
	}

	return 0;
}