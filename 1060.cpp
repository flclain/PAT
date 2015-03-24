#include <iostream>
#include <string>
#include <vector>

using namespace std;

void s2v(int N, vector<char> &vr, int &k, const string &s) {
	k = -1;
	vector<char> v;
	int firstNoneZero = -1;
	int dotPos = -1;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '.') {
			dotPos = i;
			break;
		}
	}
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] != '0' && s[i] != '.') {
			firstNoneZero = i;
			break;
		}
	}

	if(-1 != firstNoneZero){
		if(-1 == dotPos) {
			k = s.size() - firstNoneZero;
			for(int i = firstNoneZero; i < s.size(); ++i)
				v.push_back(s[i]);
		}
		else if(firstNoneZero > dotPos){
			k = -(firstNoneZero - dotPos - 1);
			for(int i = firstNoneZero; i< s.size(); ++i)
				v.push_back(s[i]);
		}
		else {
			k = dotPos - firstNoneZero;
			for(int i = firstNoneZero; i < s.size(); ++i)
				if('.' != s[i])
					v.push_back(s[i]);
		}
	}
	else {
		k = 0;
	}

	if(v.size() < N) {
		vr = v;
		for(int i = 0; i < N-v.size(); ++i) {
			vr.push_back('0');
		}
	}
	else {
		for(int i = 0; i < N; ++i) {
			vr.push_back(v[i]);
		}
	}
}

void printfV(const vector<char> &v, int k) {
	cout << "0.";
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	cout << "*10^" << k;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	int k1, k2;
	vector<char> v1;
	vector<char> v2;
	s2v(N, v1, k1, s1);
	s2v(N, v2, k2, s2);
	if(k1 == k2 && v1 == v2) {
		cout << "YES ";
		printfV(v1, k1);
		cout << endl;
	}
	else {
		cout << "NO ";
		printfV(v1, k1);
		cout << " ";
		printfV(v2, k2);
		cout << endl;
	}

	return 0;
}