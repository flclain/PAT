#include <iostream>
#include <string>
#include <sstream>

#include <cstdlib>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int num = 0;
	for(int i = 0; i < s.size(); ++i) {
		num += s[i] - '0';
	}	
	const char *numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	stringstream ss;
	ss << num;
	ss >> s;
	for(int i = 0; i < s.size()-1; ++i) {
		cout << numbers[s[i] - '0'] << " ";
	}
	cout << numbers[s[s.size()-1] - '0'] << endl;

	return 0;
}