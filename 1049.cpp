#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int i = 1;
	int cur, before, after;
	int result = 0;
	while( 0 != (n/i) ) {
		cur = (n/i) % 10;
		before = n / (i * 10);
		after = n - n / (i) * i;

		if(cur > 1) {
			result += (before + 1) * i;
		}
		else if(cur == 1) {
			result += before * i + (after + 1);
		}
		else if(cur < 1) {
			result += before * i;
		}
		i *= 10;
	}

	cout << result << endl;

	return 0;
}