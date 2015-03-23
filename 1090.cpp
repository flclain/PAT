#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	r = 1.0 + r / 100;
	vector<int> pre(N, 0);
	for(int i = 0; i < N; ++i) {
		scanf("%d", &pre[i]);
	}
	vector<int> root;
	vector< vector<int> > v(N, vector<int>());
	for(int i = 0; i < pre.size(); ++i) {
		if(-1 == pre[i])
			root.push_back(i);
		else {
			v[ pre[i] ].push_back(i);
		}
	}
	int curNum = 0, curLen = 0, preNum = 0;
	queue<int> q;
	for(int i = 0; i < root.size(); ++i) {
		q.push(root[i]);
		curNum++;
	}
	preNum = curNum;
	curNum = 0;
	q.push(-2);
	
	while(q.size() != 0) {
		if(-2 == q.front() && q.size() == 1) {
			q.pop();
			break;
		}
		else if(-2 == q.front()) {
			q.pop();
			q.push(-2);
			preNum = curNum;
			curNum = 0;
			++curLen;
			continue;
		}
		
		int curIndex = q.front();
		q.pop();
		for(int i = 0; i < v[curIndex].size(); ++i) {
			q.push(v[curIndex][i]);
			curNum++;
		}
		// curNum += v[curIndex].size();
	}
	
	double result = P;
	for(int i = 0; i < curLen; ++i) {
		result *= r;
	}
	
	// cout << curLen << " " << preNum << endl;
	printf("%.2f %d\n", result, preNum);

	return 0;
}
