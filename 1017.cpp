#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Customer {
	int arriveTime;
	int processTime;
};

const int beginTime = 8 * 3600;
const int endTime = 17 * 3600 + 1;

bool cmp(const Customer &lhs, const Customer &rhs) {
	return lhs.arriveTime < rhs.arriveTime;
}

int main(int argc, char *argv[]) {
	int N, K;
	scanf("%d%d", &N, &K);
	int hh, mm, ss, process, tmpTime;
	Customer customer;
	vector<Customer> serve;
	for(int i = 0; i < N; ++i) {
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &process);
		tmpTime = ss + mm * 60 + hh * 3600;
		if(tmpTime < endTime) {
			customer.arriveTime = tmpTime;
			if(process > 60)
				process = 60;
			customer.processTime = process * 60;
			serve.push_back(customer);
		}
	}
	vector<int> nowTime(K, beginTime);
	sort(serve.begin(), serve.end(), cmp);
	int p = 0;
	int waitTime = 0;
	for(; p < K && p < serve.size(); ++p) {
		if(serve[p].arriveTime < beginTime) {		
			waitTime += beginTime - serve[p].arriveTime;
			nowTime[p] += serve[p].processTime;
		}
		else
			nowTime[p] = serve[p].arriveTime + serve[p].processTime;
	}
	
	for(; p < serve.size(); ++p) {
		int windowId = 0, minTime = nowTime[0];
		for(int i = 1; i < K; ++i) {
			if(nowTime[i] < minTime) {
				minTime = nowTime[i];
				windowId = i;
			}
		}
		// if(minTime >= endTime)
		// 	break;
		if(serve[p].arriveTime < nowTime[windowId]) {
			waitTime += nowTime[windowId] - serve[p].arriveTime;
			nowTime[windowId] += serve[p].processTime; 
		}
		else
			nowTime[windowId] = serve[p].arriveTime + serve[p].processTime; 
	}

	// for(; p < serve.size(); ++p) {
	// 	waitTime += endTime - serve[p].arriveTime - 1;
	// }

	if(0 == p)
		printf("0.0\n");
	else
		printf("%.1f", double(waitTime) / (p * 60) );

	return 0;
}