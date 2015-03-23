#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool cmp(const string &lhs, const string &rhs){
	string a = lhs, b = rhs;
	a.append(rhs);
	b.append(lhs);
	return a < b;
}

int main(int argc, char *argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	bool start = false;
	for(int i = 0; i < v.size(); ++i) {
		if(start) {
			cout << v[i];
		}
		else {
			for(int j = 0; j < v[i].size(); ++j) {
				if(start) {
					cout << v[i][j];
				}
				else if(!start && '0' != v[i][j]) {
					start = true;
					cout << v[i][j];
				}
			}
		}	
	}
	if(!start)
		cout << "0";
	cout << endl;
	return 0;
}