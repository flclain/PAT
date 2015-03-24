#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Hog{
public:
	int a;
	int b;
	int c;
};

int main(int argc, char const *argv[])
{
	Hog A, B;
	scanf("%d.%d.%d %d.%d.%d", &A.a, &A.b, &A.c, &B.a, &B.b, &B.c);
	Hog C;
	int t;
	C.c = (A.c + B.c) % 29;
	t = (A.c + B.c) / 29;
	C.b = (A.b + B.b + t) % 17;
	t = (A.b + B.b + t) / 17;
	C.a = A.a + B.a + t;
	printf("%d.%d.%d\n", C.a, C.b, C.c);
	return 0;
}