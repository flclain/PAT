#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Man {
public:
	string _id;
	int _virtue;
	int _talent;
};

bool cmp(const Man &lhs, const Man &rhs) {
	if(lhs._virtue + lhs._talent == rhs._virtue + rhs._talent) {
		if(lhs._virtue != rhs._virtue)
			return lhs._virtue > rhs._virtue;
		else
			return lhs._id < rhs._id;
	}
	else
		return lhs._virtue + lhs._talent > rhs._virtue + rhs._talent;
}

int main(int argc, char *argv[]) {
	int N, L, H;
	cin >> N >> L >> H;
	vector< vector<Man> > man( 4, vector<Man>() );
	Man tmp;
	for(int i = 0; i < N; ++i) {
		cin >> tmp._id;
		scanf("%d%d", &tmp._virtue, &tmp._talent);
		if(tmp._virtue < L || tmp._talent < L)
			continue;
		if(tmp._virtue >= H && tmp._talent >= H) {
			man[0].push_back(tmp);
		}
		else if(tmp._virtue >= H && tmp._talent < H) {
			man[1].push_back(tmp);
		}
		else if(tmp._virtue < H && tmp._talent < H && tmp._virtue >= tmp._talent) {
			man[2].push_back(tmp);
		}
		else {
			man[3].push_back(tmp);
		}
	}

	int actual = 0;
	for(int i = 0; i < 4; ++i) {
		actual += man[i].size();
		sort(man[i].begin(), man[i].end(), cmp);
	}
	cout << actual << endl;
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < man[i].size(); ++j){
			cout << man[i][j]._id;
			printf(" %d %d\n", man[i][j]._virtue, man[i][j]._talent);
		}
	}

	return 0;
}