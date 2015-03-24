#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
	int N;
	scanf("%d\n", &N);
	if(0 == N) {
		printf("nai\n");
		return 0;
	}
	vector<string> v(N);
	for(int i = 0; i < N; ++i) {
		getline(cin, v[i]);
	}
	vector<char> suffix;
	
	for(int index = 1; index <= v[0].size(); ++index) {
		bool allequal = true;
		char cur = v[0][v[0].size() - index];
		for(int i = 0; i < v.size(); ++i) {
			if(v[i].size() - index < 0 || v[i][v[i].size() - index] != cur) {
				allequal = false;
				break;
			}
		}
		if(allequal) {
			suffix.push_back(cur);
		}
		else {
			break;
		}
	}
	
	if(0 == suffix.size()) {
		printf("nai\n");
	}
	else {
		for(int i = suffix.size() - 1; i >= 0; --i) {
			cout << suffix[i];
		}
		printf("\n");
	}

	return 0;
}