#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

int all;

// int forward(vector< vector<int> > &w, int L, int index) {
// 	if(L <= 0 || index >= w.size())
// 		return 0;
// 	set<int> s;
// 	s.insert(index);
// 	vector<int> v1;
// 	set<int> s2;
// 	vector<int> v2;
// 	v1.push_back(index);
// 	for(int i = 0; i < L; ++i) {
// 		for(int j = 0; j < v1.size(); ++j) {
// 			int cur = v1[j];
// 			for(int k = 0; k < w[cur].size(); ++k) {
// 				// v2.push_back(w[cur][k]);
// 				if(s.find(w[cur][k]) == s.end()) {
// 					s2.insert( w[cur][k] );
// 				}
// 			}
// 		}
// 		v1.clear();
// 		for(set<int>::iterator iter = s2.begin(); iter != s2.end(); ++iter) {
// 			s.insert(*iter);
// 			v1.push_back(*iter);
// 		}
// 		s2.clear();
// 	}
// 	return s.size() - 1;
// }

int forward(vector< vector<int> > &w, int L, int index, int N) {
	if(L <= 0 || index >= w.size())
		return 0;
	int curL = 0;
	queue<int> q;
	q.push(index);
	q.push(-1);
	vector<int> visit(N+1, 0);
	visit[index] = 1;
	while(curL < L) {

		// cout << "curL is :" << curL << endl;

		// vector<int> tmpV;
		// while(q.size() != 0) {
		// 	cout << q.front() <<" ";
		// 	tmpV.push_back(q.front());
		// 	q.pop();
		// }
		// cout << endl;
		// for(int i = 0; i < tmpV.size(); ++i)
		// 	q.push(tmpV[i]);



		if(q.front() == -1 && q.size() == 1)
			break;
		else if(q.front() == -1) {
			++curL;
			q.pop();
			q.push(-1);
			continue;
		}
		for(int i = 0; i < w[q.front()].size(); ++i) {
			if(visit[ w[q.front()][i] ] == 0) {
				visit[ w[q.front()][i] ] = 1;
				q.push( w[q.front()][i] );
			}
		}
		q.pop();
	}
	int result = 0;
	for(int i = 0; i < visit.size(); ++i){
		if(1 == visit[i]) {
			++result;
			// cout << i <<" ";
		}
	}
	// cout << endl;
	return result - 1;

}



int main(int argc, char *argv[]) {
	int N, L;
	scanf("%d%d", &N, &L);
	vector< vector<int> > w( N+1, vector<int>() );
	vector<int> f(N+1, 0);
	int tmp;
	for(int i = 1; i <= N; ++i) {
		scanf("%d", &tmp);
		int index;
		
		for(int j = 0; j < tmp; ++j) {
			scanf("%d", &index);
			w[index].push_back(i);
		}
	}
	// all = 0;
	// for(int i = 0; i < f.size(); ++i)
	// 	all += f[i];
	
	// printf("all point %d", all);

	scanf("%d", &tmp);
	for(int i = 0; i < tmp; ++i) {
		int index;
		scanf("%d", &index);
		printf("%d\n", forward(w, L, index, N));
	}

	return 0;
}