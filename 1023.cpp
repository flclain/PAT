#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void bigPlus(string a, string b, vector<int> &result) {
	if(a.size() < b.size())
		swap(a, b);
	int t = 0;
	int sum;
	for(int i = a.size()-1; i >= 0 ; --i) {
		sum = a[i] - '0' + b[i] - '0' + t;
		result.push_back(sum % 10);
		t = sum / 10;
	}
	if(0 != t) {
		result.push_back(t);
	}
}

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	vector<int> result;
	bigPlus(num, num, result);
	int a[10];
	int b[10];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for(int i = 0; i < num.size(); ++i) {
		++a[num[i] - '0'];
	}
	for(int i = 0; i < result.size(); ++i) {
		++b[result[i]];
	}
	bool isEqual = true;
	for(int i = 0; i < 10; ++i) {
		if(a[i] != b[i]) {
			isEqual = false;
			break;
		}
	}
	if(isEqual) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	for(int i = result.size()-1; i >= 0; --i) {
		cout << result[i];
	}
	cout << endl;
	return 0;
}