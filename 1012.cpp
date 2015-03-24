#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Student{
public:
	string id;
	int A;
	int C;
	int M;
	int E;
	bool operator < (const Student & rhs) const {
		return id < rhs.id;
	}
	bool operator == (const Student & rhs) const {
		return id == rhs.id;
	}
};

bool cmpID(const Student &lhs, const Student &rhs)  {
	return lhs.id < rhs.id;
}

bool cmp(int a, int b){
	return a > b;
}

vector<Student> vs;
vector<string> vid;
map<string, vector<int> > m;
int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	Student tmpStudent;
	for(int i = 0; i < N; ++i) {
		cin >> tmpStudent.id >> tmpStudent.C >> tmpStudent.M
			>> tmpStudent.E;
		tmpStudent.A = tmpStudent.C + tmpStudent.M + tmpStudent.E;
		vs.push_back(tmpStudent);
		m[tmpStudent.id] = vector<int>(4, -1);
	}	
	
	string tmpStr;
	for(int i = 0; i < M; ++i) {
		cin >> tmpStr;
		vid.push_back(tmpStr);
		m[tmpStr] = vector<int>(4, -1);
		// m.insert(pair<string, vector<int> >(tmpStr, vector<int>(4, -1)) );
	}

	sort(vs.begin(), vs.end(), cmpID);
	vector<Student>::iterator it = unique(vs.begin(), vs.end());
	vs.erase(it, vs.end());

	vector<int> fun;
	
	for(int i = 0; i < vs.size(); ++i)
		fun.push_back(vs[i].A);
	sort(fun.begin(), fun.end());
	
	for(int i = 0; i < vs.size(); ++i){
		m[vs[i].id][0] = fun.end() - upper_bound(fun.begin(), fun.end(), vs[i].A) + 1;
		// cout << vs[i].id << " " << vs[i].A << " " << m[vs[i].id][0] << endl;
	}
	fun.clear();

	for(int i = 0; i < vs.size(); ++i)
		fun.push_back(vs[i].C);
	sort(fun.begin(), fun.end());
	for(int i = 0; i < vs.size(); ++i){
		m[vs[i].id][1] = fun.end() - upper_bound(fun.begin(), fun.end(), vs[i].C) + 1;
	}
	fun.clear();

	for(int i = 0; i < vs.size(); ++i)
		fun.push_back(vs[i].M);
	sort(fun.begin(), fun.end());
	for(int i = 0; i < vs.size(); ++i){
		m[vs[i].id][2] = fun.end() - upper_bound(fun.begin(), fun.end(), vs[i].M) + 1;
	}
	fun.clear();

	for(int i = 0; i < vs.size(); ++i)
		fun.push_back(vs[i].E);
	sort(fun.begin(), fun.end());
	for(int i = 0; i < vs.size(); ++i){
		m[vs[i].id][3] = fun.end() - upper_bound(fun.begin(), fun.end(), vs[i].E) + 1;
	}

	const char printTable[4] = {'A', 'C', 'M', 'E'};
	for(int i = 0; i < vid.size(); ++i) {
		if( m[vid[i]][0] == -1)
			cout << "N/A" << endl;
		else {
			int result = *(min_element(m[vid[i]].begin(), m[vid[i]].end()));
			for(int j = 0; j < 4; ++j) {
				if(result == m[vid[i]][j]) {
					cout << result << " " << printTable[j] << endl;
					break;
				}
			}
		}
	}

	return 0;
}
