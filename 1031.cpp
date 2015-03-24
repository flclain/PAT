#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int n1, n2, N = s.size(), maxn1 = 0;
	for(n2 = 3; n2 <= N; ++n2) {
		if((N+2-n2)&1)
			continue;
		else{
			n1 = (N+2-n2)/2;
			if(n2 >= n1 && n1 > maxn1)
				maxn1 = n1;
		}
	}
	n1 = maxn1;
	n2 = N+2-2*maxn1;
	for(int i = 0; i < n1-1; ++i) {
		printf("%c", s[i]);
		for(int j = 0; j < n2-2; ++j)
			printf(" ");
		printf("%c\n", s[N-1-i]);
	}
	for(int i = maxn1-1; i < n1 + n2 -1; ++i)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}