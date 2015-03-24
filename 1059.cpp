#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef unsigned long long lcc;

struct Node {
	lcc _factor;
	lcc _time;
	Node(lcc f, lcc t):_factor(f), _time(t){};
};

int main(int argc, char *argv[]) {
	lcc N;
	cin >> N;
	lcc tmp = N;
	if(1 == N) {
		printf("1=1\n");
		return 0;
	}
	cout << N << "=";
	// const lcc bound = N;
	const lcc bound = ceil(sqrt(tmp));
	vector<bool> f(bound + 1, true);

	f[0] = false;
	f[1] = false;
	// cout << ceil( sqrt(N) )<< endl;
	for(lcc i = 2; i <= bound; ++i) {
		if(false == f[i])
			continue;
		for(lcc j = i + i; j <= bound; j += i) {
			f[j] = false;
		}
	}
	
	// cout << "here" << endl;

	vector<lcc> primers;
	for(lcc i = 2; i < f.size(); ++i) {
		if(true == f[i])
			primers.push_back(i);
	}
	lcc index = 0;
	vector<Node> result;
	while(1 != N && index < primers.size() && primers[index] <= ceil(sqrt(tmp)) ) {
		// if(true == f[N]) {
		// 	result.push_back( Node(N, 1) );
		// 	break;
		// }
		int num = 0;
		while(1 != N) {
			if(N % primers[index] == 0) {
				num++;
				N /= primers[index];
			}
			else
				break;
		}
		if(0 != num) {
			result.push_back( Node(primers[index], num) );
		}
		++index;
	}
	if(true == f[N]) {
		result.push_back( Node(N, 1) );
	}
	if(0 == result.size()) {
		cout << N << endl;
	}
	else {
		if(1 == result[0]._time ) {
			cout << result[0]._factor;
		}
		else{
			cout << result[0]._factor << "^" << result[0]._time;
		}
		for(int i = 1; i < result.size(); ++i) {
			if(1 == result[i]._time)
				cout << "*" << result[i]._factor;
			else
				cout << "*" << result[i]._factor << "^" << result[i]._time;
		}
		cout << endl;
	}

	return 0;
}