#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Student {
public:
	string _name;
	string _ID;
	int _grade;

	bool operator< (const Student &rhs) const{
		return _grade > rhs._grade;
	}
};

// bool cmp(const Student &lhs, const Student &rhs) {
// 	return lhs._grade > rhs._grade;
// }

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	vector<Student> students(N);
	for(int i = 0; i < N; ++i) {
		cin >> students[i]._name >> students[i]._ID >> students[i]._grade;
	}
	int lowBound, highBound;
	cin >> lowBound >> highBound;
	sort(students.begin(), students.end());
	if(students.size() == 0 || students[0]._grade < lowBound || students[students.size()-1]._grade > highBound){
		printf("NONE\n");
	}
	else {
		for(int i = 0; i < N; ++i)
			if(students[i]._grade >= lowBound && students[i]._grade <= highBound)
				cout << students[i]._name << " " << students[i]._ID << endl;
	}


	return 0;
}