#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int now = 0, result = 0, next;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &next);
		if(now >= next) {
			result += (now - next) * 4 + 5;
		}
		else {
			result += (next - now) * 6 + 5;
		}
		now = next;
	}
	printf("%d\n", result);

	return 0;
}