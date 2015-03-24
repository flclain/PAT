#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

const int MAXNUM = 11000;

using namespace std;

int main(int argc, char *argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	vector<bool> isPrime(MAXNUM, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i < int( sqrt( double(MAXNUM) ) ); ++i) {
		if(!isPrime[i])
			continue;
		for(int j = i + i; j < MAXNUM; j += i) {
			isPrime[j] = false;
		}
	}
	
	int MSize, N;
	cin >> MSize >> N;
	// resize M
	for(int i = MSize; i < isPrime.size(); ++i) {
		if(isPrime[i]) {
			MSize = i;
			break;
		}
	}
	
	vector<bool> Ok(MSize, true);
	vector<bool> h(MSize, false);
	for(int i = 0; i < N; ++i) {
		int num, d;
		scanf("%d", &num);
		d = num % MSize;
		if(!Ok[d]) {
			printf("-");
		}
		else {
			bool findPos = false;
			int nowD;
			for(int j = 0; j < MSize; ++j) {
				nowD = (d + j * j) % MSize;
				if(!h[nowD]) {
					h[nowD] = true;
					findPos = true;
					break;
				}
			}
			if(findPos) {
				printf("%d", nowD);
			}
			else {
				Ok[d] = false;
				printf("-");
			}
		}

		if(N-1 == i) 
			printf("\n");
		else
			printf(" ");

	}
	 
	return 0;
}