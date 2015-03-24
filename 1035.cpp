#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	// vector<pair<string, string> > ori;
	vector<pair<string, string> > v;
	int n;
	cin >> n;
	string id, pword;
	bool flag = false;
	for(int i = 0; i < n; ++i) {
		flag = false;
		cin >> id >> pword;
		for(int j = 0; j < pword.size(); ++j) {
			if(pword[j] == '1')
				pword[j] = '@';
			else if(pword[j] == '0')
				pword[j] = '%';
			else if(pword[j] == 'l')
				pword[j] = 'L';
			else if(pword[j] == 'O')
				pword[j] = 'o';
			else
				continue;
			flag = true;
		}
		if(flag)
			v.push_back(pair<string, string>(id, pword));
	}

	if(0 == v.size()) {
		if(1 == n) {
			cout << "There is 1 account and no account is modified" << endl;
		}
		else {
			cout << "There are " << n << " accounts and no account is modified" << endl;
		}
	}
	else {
		cout << v.size() << endl;
		for(int i = 0; i < v.size(); ++i) {
			cout << v[i].first << " " << v[i].second << endl;
		}
	}


	return 0;
}