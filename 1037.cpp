#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b) {
	return a > b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> pc;
	vector<int> nc;
	vector<int> pp;
	vector<int> np;
	int tmp;
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		if(tmp > 0) {
			pc.push_back(tmp);
		}
		else if(tmp < 0) {
			nc.push_back(-tmp);
		}
	}
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		if(tmp > 0) {
			pp.push_back(tmp);
		}
		else if(tmp < 0) 
			np.push_back(-tmp);
	}

	sort(pc.begin(), pc.end(), cmp);
	sort(nc.begin(), nc.end(), cmp);
	sort(pp.begin(), pp.end(), cmp);
	sort(np.begin(), np.end(), cmp);

	int result = 0;
	for(int i = 0, j = 0; i < pc.size() && j < pp.size(); ++i, ++j) {
		result += pc[i] * pp[j];
	}
	for(int i = 0, j = 0; i < nc.size() && j < np.size(); ++i, ++j) {
		result += nc[i] * np[j];
	}

	cout << result << endl;
	return 0;
}