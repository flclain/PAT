#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Student {
public:
	int id;
	vector<int> p;
	vector<int> done;
	int total;
	int perfect;
};

bool cmp(const Student &lhs, const Student &rhs) {
	if(lhs.total != rhs.total) {
		return lhs.total > rhs.total;
	}
	else {
		if(lhs.perfect != rhs.perfect) {
			return lhs.perfect > rhs.perfect;
		}
		else {
			return lhs.id < rhs.id;
		}
	}

}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N, K, M;
	cin >> N >> K >> M;
	vector<int> full(K);
	for(int i = 0; i < K; ++i)
		cin >> full[i];

	vector<Student> v(N);
	for(int i = 0; i < N; ++i) {
		vector<int> tmp(K, -1);
		vector<int> tmp2(K, -2);
		v[i].p = tmp;
		v[i].done = tmp2;
		v[i].total = 0;
		v[i].perfect = 0;
	}
	for(int i = 0; i < M; ++i) {
		int sid, pid, score;
		cin >> sid >> pid >> score;
		sid--;
		pid--;
		if(score >= 0)
			v[sid].done[pid] = 0;
		v[sid].p[pid] = max(v[sid].p[pid], score);
		v[sid].p[pid] = max(v[sid].p[pid], 0);
		//if(score != -1) {
		//	v[sid].total += score;
		//	if(full[pid] == score)
		//		v[sid].perfect += 1;
		//}
		v[sid].id = sid;
		
	}

	for(int i = 0; i < v.size(); ++i) {
		v[i].total = 0;
		for(int j = 0; j < K; ++j) {
			if(v[i].p[j] != -1)
				v[i].total += v[i].p[j];
			if(full[j] == v[i].p[j])
				v[i].perfect += 1;
		}
	}

	sort(v.begin(), v.end(), cmp);
	vector<Student> result;

	for(int i = 0; i < v.size(); ++i) {
		bool allNone = true;
		/*if(v[i].total != 0)
			allNone = false;*/
		for(int j = 0; j < K; ++j) {
			if(-2 != v[i].done[j]) {
				allNone = false;
				break;
			}
		}
		if(allNone)
			continue;
		result.push_back(v[i]);
	}

	int pre = result[0].total, curRank = 1, num = 0;
	for(int i = 0; i < result.size(); ++i) {
		if(result[i].total != pre) {
			curRank += num;
			num = 1;
			pre = result[i].total;
		}
		else {
			++num;
		}
		printf("%d %05d %d", curRank, result[i].id + 1, result[i].total);
		for(int j = 0; j < K; ++j) {
			if(result[i].p[j] == -1)
				printf(" -");
			else
				printf(" %d", result[i].p[j]);
		}
		printf("\n");
	}

	return 0;
}