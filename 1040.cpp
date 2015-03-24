#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	char str[1100];
	cin.getline(str, 1010);
	string s = str;
	int result = 1;
	const int n = s.size();
	vector<bool>  f(n, false);
	for(int i = n-1; i >= 0; --i) {
		f[i] = true;
		for(int j = n-1; j >= i+1; --j) {
			if(i + 1 == j) {
				f[j] = (s[i] == s[j]);
			}
			else {
				f[j] = (s[i] == s[j]) && f[j-1];
			}
			if(f[j] && j-i+1 > result) {
				result = j-i+1;
			}
		}
	}
	cout << result << endl;


	return 0;
}