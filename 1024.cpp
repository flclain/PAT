#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long lint;

bool isPalind(string s) {
	for(int i = 0, j = s.size()-1; i < j; ++i, --j){
		if(s[i] != s[j])
			return false;
	}
	return true;
}

string bigPlus(string a, string b) {
	string result = "";
	vector<int> v;
	for(unsigned int i = 0; i < a.size(); ++i) {
		v.push_back(a[i] - '0' + b[i] - '0');
	}
	int borrow = 0;
	for(int i = v.size()-1; i >= 0; --i) {
		v[i] += borrow;
		borrow = v[i] / 10;
		result.push_back('0' + v[i] % 10);
	}
	if(0 != borrow)
		result.push_back('0' + borrow);
	reverse(result.begin(), result.end());
	return result;
}

int main(int argc, char const *argv[])
{
	string a;
	int k;
	cin >> a >> k;
	int i = 0;
	for(; i < k; ++i) {
		if(isPalind(a)) {
			break;
		}
		string b = a;
		reverse(b.begin(), b.end());
		a = bigPlus(a, b);
	} 	
	cout << a << endl;
	cout << i << endl; 
	return 0;
}
