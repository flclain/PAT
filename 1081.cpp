#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Rational {
public:
	int flag;
	int numerator;
	int denominator;
};

int gcd(int a, int b) {
	if(a == 0 || b == 0 || a == 1 || b == 1)
		return 1;
	a = abs(a);
	b = abs(b);
	if(b > a)
		swap(a, b);
	while(b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void fit(Rational &r) {
	if(0 == r.numerator) {
		r.flag = 1;
		r.denominator = 1;
		return;
	}
	int g = gcd(r.numerator, r.denominator);
	r.numerator /= g;
	r.denominator /= g;
}

void sum(Rational &lhs, Rational &rhs) {
	fit(lhs);
	fit(rhs);
	int g = gcd(lhs.denominator, rhs.denominator);
	int newD = lhs.denominator / g * rhs.denominator;
	int newN = lhs.flag * newD / lhs.denominator * lhs.numerator + rhs.flag * newD / rhs.denominator * rhs.numerator;
	if(newN < 0) {
		lhs.flag = -1;
		newN = -newN;
	}
	else
		lhs.flag = 1;
	lhs.numerator = newN;
	lhs.denominator = newD;
}

int main(int argc, char *argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<Rational> v(n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d/%d", &a, &b);
		if(a < 0) {
			v[i].flag = -1;
			a = -a;
		}
		else
			v[i].flag = 1;
		v[i].numerator = a;
		v[i].denominator = b;
	}

	Rational result;
	result.flag = 1;
	result.numerator = 0;
	result.denominator = 1;

	for(int i = 0; i < v.size(); ++i) {
		sum(result, v[i]);
	}

	fit(result);

	if(0 == result.numerator) {
		printf("0\n");
		return 0;
	}

	
	int integer = result.numerator / result.denominator;
	if(integer != 0) {
		
		if(-1 == result.flag)
			printf("-");
		
		printf("%d", integer);
	}

	if(result.denominator != 1) {
		if(integer != 0)
			printf(" ");
		else {
			if(-1 == result.flag)
				printf("-");
		}
		printf("%d/%d", result.numerator % result.denominator, result.denominator);
	}

	printf("\n");

	return 0;
}