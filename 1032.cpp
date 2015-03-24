#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[100010];
	memset(m, 0, sizeof(m));
	int root1, root2, n;
	cin >> root1 >> root2 >> n;
	if(root1 == -1 || root2 == -1){
		cout << -1 << endl;
		return 0;
	}

	char tmp;
	int adr, next;
	for(int i = 0; i < n; ++i) {
		cin >> adr >> tmp >> next;
		m[adr] = next; 
	}
	// vector<int> v;
	int m1[100010];
	memset(m1, 0, sizeof(m1));
	int cur = root1;
	while(cur != -1) {
		m1[cur] = 1;
		cur = m[cur];
	}

	int result = -1;
	cur = root2;
	while(cur != -1) {
		if(m1[cur] == 1) {
			result = cur;
			break;
		}
		cur = m[cur];
	}
	if(-1 != result)
		printf("%.05d\n", result);
	else
		cout << result << endl;
	return 0;
}