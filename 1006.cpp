#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class checkRecord
{
public:
	string id;
	string checkIn;
	string checkOut;
	/* data */
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<checkRecord> v;
	for(int i = 0; i < n; ++i) {
		checkRecord tmp;
		cin >> tmp.id >> tmp.checkIn >> tmp.checkOut;
		v.push_back(tmp);
	}
	string earlyId, lateId;
	string earlyTime = "99:99:99", lateTime = "00:00:00";
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].checkIn <= earlyTime) {
			earlyId = v[i].id;
			earlyTime = v[i].checkIn;
		}
	}
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].checkOut >= lateTime) {
			lateId = v[i].id;
			lateTime = v[i].checkOut;
		}
	}
	cout << earlyId << " " << lateId << endl;
	return 0;
}