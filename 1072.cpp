#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int N, M, K, D, NM;

class Gas {
public:
	double minimum;
	double average;
	int index;
	bool operator < (const Gas &rhs) const {
		if(minimum != rhs.minimum)
			return minimum > rhs.minimum;
		else {
			if(average != rhs.average)
				return average < rhs.average;
			else {
				return index < rhs.index;
			}
		}
	}
};


int string2int(string s) {
	// M <= 10
	if('G' == s[0]) {
		if(3 == s.size())
			return 10 + N;
		else
			return s[1] - '0' + N;
	}
	else {
		stringstream ss;
		ss << s;
		int result;
		ss >> result;
		return result;
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin >> N >> M >> K >> D;
	NM = N + M;
	vector< vector<int> > w(NM + 1, vector<int>(NM + 1, INT_MAX / 4) );
	for(int i = 1; i <= NM; ++i)
		w[i][i] = 0;
	for(int i = 0; i < K; ++i) {
		string tmp1, tmp2;
		int d, index1, index2;
		cin >> tmp1 >> tmp2 >> d;
		index1 = string2int(tmp1);
		index2 = string2int(tmp2);
		w[index1][index2] = d;
		w[index2][index1] = d;
	}

	if(N <= 0 || M <= 0) {
		cout << "No Solution" << endl;
		return 0;
	}

	vector<Gas> result;

	for(int gi = 1; gi <= M; ++gi) {
		int gIndex = gi + N;
		vector<int> d(NM+1, INT_MAX / 4);
		d[gIndex] = 0; 
		vector<bool> visited(NM+1, false);
		for(int k = 1; k <= NM; ++k) {
			int small = INT_MAX;
			int smallIndex = -1;
			for(int i = 1; i <= NM; ++i) {
				if(!visited[i] && d[i] < small) {
					small = d[i];
					smallIndex = i;
				}
			}
			visited[smallIndex] = true;
			for(int i = 1; i <= NM; ++i) {
				d[i] = min(d[i], d[smallIndex] + w[smallIndex][i]);
			}
		}

		Gas tmp;
		double tavrage = 0; 
		int tmin = INT_MAX;
		bool unReach = false;
		for(int i = 1; i <= N; ++i) {
			if(d[i] > D) {
				unReach = true;
				break;
			}
			tmin = min(tmin, d[i]);
			tavrage += d[i];
		}
		if(!unReach) {
			tmp.average = tavrage / N;
			tmp.minimum = tmin;
			tmp.index = gi;
			result.push_back(tmp);
		}
	}


	if(0 == result.size()) {
		cout << "No Solution" << endl;
	}
	else {
		sort(result.begin(), result.end());
		printf("G%d\n", result[0].index);
		printf("%.1f %.1f\n", result[0].minimum, result[0].average);
	}

	return 0;
}