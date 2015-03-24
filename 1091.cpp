#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

//#define DEBUG

using namespace std;

bool MRI[1300][130][70];
int M, N, L, T;
int volume;

class Point {
public:
	int x;
	int y;
	int z;
	Point(int i, int j, int k): x(i), y(j), z(k){};
};

stack<Point> s;


void dfs(int x, int y, int z) {
	if(!MRI[x][y][z])
		return;
	s.push(Point(x, y, z));
	while(!s.empty()) {
		x = s.top().x;
		y = s.top().y;
		z = s.top().z;
		s.pop();
		if(!MRI[x][y][z])
			continue;
		MRI[x][y][z] = false;
		++volume;
		if(x > 0)
			s.push(Point(x - 1, y, z));
		if(y > 0)
			s.push(Point(x, y - 1, z));
		if(z > 0)
			s.push(Point(x, y, z - 1));
		if(x < M - 1)
			s.push(Point(x + 1, y, z));
		if(y < N - 1)
			s.push(Point(x, y + 1, z));
		if(z < L - 1)
			s.push(Point(x, y, z + 1));
	}
}

//void dfs(int x, int y, int z) {
//	if(!MRI[x][y][z])
//		return;
//
//	MRI[x][y][z] = false;
//	++volume;
//
//	if(x > 0)
//		dfs(x - 1, y, z);
//	if(y > 0)
//		dfs(x, y - 1, z);
//	if(z > 0)
//		dfs(x, y, z - 1);
//	if(x < M - 1)
//		dfs(x + 1, y, z);
//	if(y < N - 1)
//		dfs(x, y + 1, z);
//	if(z < L - 1)
//		dfs(x, y, z + 1);
//
//}



int main(int argc, char *argv[]) {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
#endif
	
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for(int k = 0; k < L; ++k) {
		for(int i = 0; i < M; ++i) {
			for(int j = 0; j < N; ++j) {
				int tmp;
				scanf("%d", &tmp);
				if(1 == tmp)
					MRI[i][j][k] = true;
				else
					MRI[i][j][k] = false;
			}
		}
	}
	
	int result = 0;

	for(int k = 0; k < L; ++k) {
		for(int i = 0; i < M; ++i) {
			for(int j = 0; j < N; ++j) {
				volume = 0;
				dfs(i, j, k);
				if(volume >= T)
					result += volume;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}