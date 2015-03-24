#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {

	string ori, act;
	cin >> ori >> act;
	int j = 0;
	set<char> result;
	for(int i = 0; i < ori.size(); ++i) {
		if(j >= act.size() || ori[i] != act[j]) {
			if(ori[i] >= 'a' && ori[i] <= 'z')
				ori[i] = ori[i] - 'a' + 'A';
			if( result.end() == result.find(ori[i]) ) {
				cout << ori[i];
				result.insert(ori[i]);
			}
		}
		else {
			++j;
		}
	}
	cout << endl;
	return 0;
}