#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;
const int MAXNUM = 100010;
int f[MAXNUM];

int translateTo10(int number, int radix) {
	if(10 == radix)
		return number;
	int result = 0;
	int base = 1;
	while(0 != number) {
		result += number % 10 * base;
		base *= radix;
		number /= 10;
	}
	return result;
}

int translateToRadix(int number, int radix) {
	if(10 == radix)
		return number;
	int result = 0;
	int base = 1;
	while(0 != number) {
		result += number % radix * base;
		base *= 10;
		number /= radix;
	}
	return result;

}

int reserveInt(int number) {
	int result = 0;
	while(0 != number) {
		result = result * 10 + number % 10;
		number /= 10;
	}
	return result;
}

int reserveNum(int number, int radix) {
	int result = 0;
	while(0 != number) {
		result = result * radix + number % radix;
		number /= radix;
	}
	return result;
}

int main(int argc, char *argv[]) {
	memset( f, 0, sizeof(f) );
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i < int( pow(1.0*MAXNUM, 0.5) ) + 1; ++i) {
		if(1 == f[i])
			continue;
		for(int j = i + i; j < MAXNUM - 1; j += i) {
			f[j] = 1;
		}
	}

	int number, radix;
	while(true) {
		scanf("%d", &number);
		if(number < 0)
			break;
		scanf("%d", &radix);
		if( 0 == f[ number ] && 
		//	0 == f[translateTo10( reserveInt( translateToRadix(number, radix) ), radix) ]) {
			0 == f[ reserveNum(number, radix) ] ){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}

	//	printf("%d\n", reserveInt( translateToRadix(number, radix) ));
	}

	return 0;
}