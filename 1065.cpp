#include <iostream>
#include <cstdio>

using namespace std;

typedef long long lint;

bool CompareBigInt(lint a, lint b, lint c) {
	lint sum = a + b;
	if(a > 0 && b > 0 && sum <= 0)
		return true;
	if(a < 0 && b < 0 && sum >= 0)
		return false;
	return sum > c;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	lint  a, b, c;
	bool result;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		result = CompareBigInt(a, b, c);
		cout << "Case #" << i + 1 << ": ";
		if(result)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}