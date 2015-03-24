#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int closeTime = (17- 8) * 60;

struct Customer
{
	int processTime;
	int leaveTime;
};

int main(int argc, char *argv[]) {
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	vector<Customer> customers(K);
	for(int i = 0; i < K; ++i){
		scanf("%d", &customers[i].processTime);
		customers[i].leaveTime = INT_MAX;
	}
	int p = 0, id;
	vector<int> now(N, 0);
	vector< queue<int> > mQueue(N);
	for(; p < K && p < N*M; ++p) {
		id = p % N;
		customers[p].leaveTime = now[id] + customers[p].processTime;
		now[id] = customers[p].leaveTime;
		mQueue[id].push(p);
	}
	for(; p < K; ++p) {
		int minTime = INT_MAX;
		int index = 0;
		for(int i = 0; i < N; ++i) {
			int topId = mQueue[i].front();
			if(minTime > customers[topId].leaveTime) {
				minTime = customers[topId].leaveTime;
				index = i;
			}
		}
		customers[p].leaveTime = now[index] + customers[p].processTime;
		now[index] = customers[p].leaveTime;
		mQueue[index].pop();
		mQueue[index].push(p);
	}

	int query;
	for(int i = 0; i < Q; ++i) {
		scanf("%d", &query);
		--query;
		if(customers[query].leaveTime - customers[query].processTime >= closeTime) {
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n", 8 + customers[query].leaveTime / 60, customers[query].leaveTime % 60);
		}
	}



	return 0;
}