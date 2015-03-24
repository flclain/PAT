#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

//#define DEBUG

using namespace std;

typedef long long lint;

lint gcd(lint a, lint b) {
	a = abs(a);
	b = abs(b);
	lint result = 1;
	if(a == 0 || b == 0)
		return 1;
	lint tmp;
	while(b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void reduce(lint &a, lint &b) {
	lint cut = gcd(a, b);
	a /= cut;
	b /= cut;
}

void printR(lint a, lint b) {
	reduce(a, b);
	
	bool isNeg = false;
	if(a < 0) {
		isNeg = true;
		printf("(-");
		a = -a;
	}

	if(0 == a || 1 == b) {
		printf("%lld", a);
	}
	else {
		lint iPart = a / b;
		if(0 != iPart) { 
			printf("%lld %lld/%lld", iPart, a % b, b);
		}
		else {
			printf("%lld/%lld", a, b);
		}
	}
	if(isNeg) 
		printf(")");
}

void rSum(lint a, lint b, lint c, lint d) {
	lint f = b * d / gcd(b, d);
	lint e = f / b * a + f / d * c;
	reduce(e, f);
	printR(a, b);
	cout << " + ";
	printR(c, d);
	cout << " = ";
	printR(e, f);
	printf("\n");
}

void rDifference(lint a, lint b, lint c, lint d) {
	lint f = b * d / gcd(b, d);
	lint e = f / b * a - f / d * c;
	reduce(e, f);
	printR(a, b);
	cout << " - ";
	printR(c, d);
	cout << " = ";
	printR(e, f);
	printf("\n");
}

void rProduct (lint a, lint b, lint c, lint d) {
	lint f = b * d;
	lint e = a * c;
	reduce(e, f);
	printR(a, b);
	cout << " * ";
	printR(c, d);
	cout << " = ";
	printR(e, f);
	printf("\n");
}


void rQuotient (lint a, lint b, lint c, lint d) {
	lint f = b * c;
	lint e = a * d;

	if(e < 0 && f < 0 || e > 0 && f < 0) {
		e = -e;
		f = -f;
	}

	reduce(e, f);
	printR(a, b);
	cout << " / ";
	printR(c, d);
	cout << " = ";
	if(0 != f)
		printR(e, f);
	else
		printf("Inf");
	printf("\n");
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
#endif
	// 2/3 -4/2
	lint a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	
	reduce(a, b);
	reduce(c, d);
	
	rSum(a, b, c, d);
	rDifference(a, b, c, d);
	rProduct(a, b, c, d);
	rQuotient(a, b, c, d);

	return 0;
}