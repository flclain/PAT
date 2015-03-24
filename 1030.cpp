#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

const int INF = 0x6fffffff;

int main(int argc, char* argv[]) {
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	vector<int> d(N, INF);
	vector<int> c(N, INF);
	d[S] = 0;
	c[S] = 0;
	vector< vector<int> > weight(N, vector<int>(N, INF));
	vector< vector<int> > cost(N, vector<int>(N, INF));
	for(int i = 0; i < N; ++i) {
		weight[i][i] = 0;
		cost[i][i] = 0;
	}
	vector<int> pre(N, 0);
	pre[S] = S;
	int a, b, tmpW, tmpC;
	for(int i = 0; i < M; ++i) {
		scanf("%d%d%d%d", &a, &b, &tmpW, &tmpC);
		weight[a][b] = weight[b][a] = tmpW;
		cost[a][b] = cost[b][a] = tmpC;
	}

	vector<int> v(N, 0);
	for(int i = 0; i < N; ++i) {
		int x, y = INF;
		for(int j = 0; j < N; ++j) {
			if(0 == v[j] && d[j] < y) {
				y = d[j];
				x = j;
			}
		}
		v[x] = 1;
		for(int j = 0; j < N; ++j) {
			if(d[x] + weight[x][j] < d[j]) {
				d[j] = d[x] + weight[x][j];
				pre[j] = x;
				c[j] = c[x] + cost[x][j];

				// printf("x:%d j:%d c[j]:%d", x, j, c[j]);	
			}
			if(d[x] + weight[x][j] == d[j] && c[x] + cost[x][j] < c[j]) {
				pre[j] = x;
				c[j] = c[x] + cost[x][j];

				// printf("x:%d j:%d c[j]:%d", x, j, c[j]);
			}
		}
	}

	stack<int> s;
	int cur = D;

	while(pre[cur] != cur) {
		s.push(cur);
		cur = pre[cur];
	}
	s.push(cur);

	while(!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("%d %d\n", d[D], c[D]);

	return 0;
}