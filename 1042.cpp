#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	vector<string> v;
	v.push_back("");
	vector<string> s4(4);
	s4[0] = "S";
	s4[1] = "H";
	s4[2] = "C";
	s4[3] = "D";
	for(int k = 0; k < 4; ++k) {
		for(int i = 1; i <= 13; ++i) {
			string s = s4[k];
			if(i < 10)
				s.push_back('0' + i);
			else {
				s.push_back('0' + i / 10);
				s.push_back('0' + i % 10);
			}
			v.push_back(s);
		}
	}
	v.push_back("J1");
	v.push_back("J2");

	// for(int i = 1; i <= 54; ++i) {
	// 	cout << v[i] << " ";
	// }

	int n;
	scanf("%d", &n);

	int a[55];
	int b[55];
	int c[55];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= 54; ++i) {
		scanf("%d", &a[i]);
		b[i] = i;
	}

	for(int k = 0; k < n; ++k) {
		for(int i = 1; i <= 54; ++i) {
			c[ a[i] ] = b[i];
		}
		for(int i = 1; i <= 54; ++i) {
			b[i] = c[i];
		}
	}

	cout << v[ b[1] ];
	for(int i = 2; i <= 54; ++i) {
		cout << " " << v[ b[i] ];
	}
	cout << endl;
	return 0;
}
