#include <iostream>
#include <string>

using namespace std;

class Student{
public:
	string name;
	string id;
	int score;
};

int main(int argc, char const *argv[])
{

	Student maxF, minM;
	maxF.score = -1;
	minM.score = 9999;
	int n;
	Student tmp;
	char sex;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> tmp.name >> sex >> tmp.id >> tmp.score;
		if(sex == 'M') {
			if(tmp.score < minM.score) {
				minM = tmp;
			}
		}
		else {
			if(tmp.score > maxF.score) {
				maxF = tmp;
			}
		}
	}
	if(maxF.score == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << maxF.name << " " << maxF.id << endl;
	}

	if(minM.score == 9999) {
		cout << "Absent" << endl;
	}
	else {
		cout << minM.name << " " << minM.id << endl;
	}

	if(maxF.score != -1 && minM.score != 9999) {
		cout << maxF.score - minM.score << endl;
	}
	else {
		cout << "NA" << endl;
	}
	
	return 0;
}