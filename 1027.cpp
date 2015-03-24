#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int ce[3];
	cin >> ce[0] >> ce[1] >> ce[2];
	int cm[3][2];
	for(int i = 0; i < 3; ++i) {
		cm[i][0] = ce[i] / 13;
		cm[i][1] = ce[i] % 13;
	}
	cout << "#";
	char tmp;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 2; ++j) {
			if(cm[i][j] > 9) {
				tmp = 'A' + cm[i][j] - 10;
				cout << tmp;
			}
			else {
				cout << cm[i][j];
			}
		}
	}
	cout << endl;

	return 0;
}