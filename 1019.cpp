#include <iostream>
#include <vector>

#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long lint;

void printV(const vector<int> & v) {	
	for(int i = v.size()-1; i > 0; --i){
		cout << v[i] << " ";
	}
	cout << v[0] << endl;
}

int main(int argc, char const *argv[])
{
	lint a, radix;
	cin >> a >> radix;
	vector<int> v;
	
	do{
		v.push_back(a % radix);
		a /= radix;
	}while(0 != a);

	for(int i = 0, j = v.size()-1; i < j; ++i, --j){
		if(v[i] != v[j]) {
			cout << "No" << endl;
			printV(v);
			return 0;
		}
	}
	cout << "Yes" << endl;
	printV(v);

	return 0;
}