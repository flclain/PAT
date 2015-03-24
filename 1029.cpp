#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lint;

vector<lint> v1;
vector<lint> v2;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n1;
	scanf("%d", &n1);
	v1.resize(n1);
	for(int i = 0; i < n1; ++i)
		scanf("%lld", &v1[i]);
	int n2;
	scanf("%d", &n2);
	v2.resize(n2);
	for(int i = 0; i < n2; ++i)
		scanf("%lld", &v2[i]);

	// special case: 0
	if(n1 <= 0 || n2 <= 0) {
		if(n1 <= 0 && n2 <= 0)
			printf("0\n");
		else if(n1 <= 0)
			printf("%d\n", v2[ (n2 - 1) / 2 ]);
		else 
			printf("%d\n", v1[ (n1 - 1) / 2 ]);
		return 0;
	}	

	int midPos = (n1 + n2 - 1) / 2;
	lint minM = min(v1[ (n1 - 1) / 2 ],  v2[ (n2 - 1) / 2 ] );
	lint maxM = max(v1[ (n1 - 1) / 2 ],  v2[ (n2 - 1) / 2 ] );

	while(minM <= maxM) {
		if(minM == maxM) {
			cout << minM << endl;
			return 0;
		}

		lint m = (maxM - minM) / 2 + minM;
		int numL = lower_bound(v1.begin(), v1.end(), m) - v1.begin() + lower_bound(v2.begin(), v2.end(), m) - v2.begin();
		int numR = upper_bound(v1.begin(), v1.end(), m) - v1.begin() + upper_bound(v2.begin(), v2.end(), m) - v2.begin();
		if(numL <= midPos && numR > midPos) {
			cout << m << endl;
			return 0;
		}
		else {
			if(numL > midPos) 
				maxM = m - 1;
			else
				minM = m + 1;
		}
	}


	lint m = minM;
	int numL = lower_bound(v1.begin(), v1.end(), m) - v1.begin() + lower_bound(v2.begin(), v2.end(), m) - v2.begin();
	int numR = upper_bound(v1.begin(), v1.end(), m) - v1.begin() + upper_bound(v2.begin(), v2.end(), m) - v2.begin();
	if(numL <= midPos && numR > midPos) {
		cout << m << endl;
		return 0;
	}
	cout << maxM << endl;


	return 0;
}