#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	getchar();
	map<string, vector<string> > m[5];
	string id;
	string title, name, keyword, publisher, year;
	for(int i = 0; i < n; ++i) {
		getline(cin, id);
		// cout << c << "--------------------_>" << id << endl;
		for(int j = 0; j < 5; ++j) {
			string tmpStr;
			getline(cin, tmpStr);
			if(2 != j)
				m[j][tmpStr].push_back(id);
			else {
				istringstream istr(tmpStr);
				while(!istr.eof()) {
					string keyword;
					istr >> keyword;
					m[j][keyword].push_back(id);
				}
			}
		}
	}
	map<string, vector<string> >::iterator iter;
	for(int i = 0; i < 5; ++i) {
		for(iter = m[i].begin(); iter != m[i].end(); ++iter) {
			sort((iter->second).begin(), (iter->second).end());
		}
	}

	cin >> n;
	getchar();
	for(int i = 0; i < n; ++i) {
		string query;
		int index;
		scanf("%d: ", &index);
		getline(cin, query);
		printf("%d: ", index);
		--index;
		cout << query << endl;
		iter = m[index].find(query);
		if(m[index].end() != iter) {
			for(int k = 0; k < (iter->second).size(); ++k) {
				cout << (iter->second)[k] << endl;
			}
		}
		else {
			cout << "Not Found" << endl;
		}
	}
	return 0;
}