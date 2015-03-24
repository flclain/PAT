#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <cstdio>
#include <cstdlib>

using namespace std;

int string2Int(string s) {
	stringstream ss;
	ss << s;
	int a;
	ss >> a;
	return a;
}

int main(int argc, char *argv[]) {
	string oriStr;
	cin >> oriStr;
	bool digitSign = true;
	if('-' == oriStr[0])
		digitSign = false;
	int digitStart = oriStr[1] - '0';
	vector<int> after;
	int index = 3;
	while('E' != oriStr[index]) {
		after.push_back(oriStr[index] - '0');
		++index;
	}
	
	++index;
	int shiftSign = true;
	if('-' == oriStr[index])
		shiftSign= false;
	int shift = 0;
	++index;
	shift = string2Int(oriStr.substr(index));
	// cout << digitSign << " " << digitStart << " " << shiftSign << " " <<  shift << endl;
	if(!digitSign)
		printf("-");
	int pos = 1;
	// cout << shiftSign << " " << shift << endl;
	if(!shiftSign && shift > 0) {
		pos -= shift;
		pos = -pos;
		printf("0.");
		for(int i = 0; i < pos; ++i){
			printf("0");
		}
		printf("%d", digitStart);
		for(int i = 0; i < after.size(); ++i)
			printf("%d", after[i]);
		printf("\n");
	}
	else {
		printf("%d", digitStart);
		pos--;
		pos += shift;
		for(int i = 0; i < after.size(); ++i) {
			if(pos == i)
				printf(".");
			printf("%d", after[i]);
		}
		// cout << pos <<" " << after.size() << " " << pos - after.size() << endl;
		for(int i = 0; i < pos - int(after.size()); ++i)
			printf("0");
		printf("\n");
	}

	return 0;
}