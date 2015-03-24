#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	double bet[3][3];
	const char out[3] = {'W', 'T', 'L'};
	for(int i = 0; i < 3; ++i)
		scanf("%lf%lf%lf", &bet[i][0], &bet[i][1], &bet[i][2]);
	double a[3];
	double result = 1.0;
	for(int i = 0; i < 3; ++i) {
		a[i] = max( bet[i][0], max(bet[i][1], bet[i][2]) );
		result *= a[i];
		for(int j = 0; j < 3; ++j) {
			if(a[i] == bet[i][j]) {
				printf("%c ", out[j]);
				break;
			}
		}
	}
	result = (a[0] * a[1] * a[2] * 0.65 - 1.0) * 2.0 ;
	printf("%.2f\n", result);

	return 0;
}
