#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int m, n, k;
	cin >> m >> n >> k;
	for(int i = 0; i < k; ++i) {
		stack<int> s1;
		stack<int> s2;
		vector<int> v;
		int now;
		for(int j = n; j > 0; --j){
			scanf("%d", &now);
			v.push_back(now);
			s2.push(j);
		}
		bool posible = true;
		for(int j = 0; j < n; ++j){
			if(false == posible)
				break;
			if(s1.empty() || s1.top() < v[j]) {
				while(true) {
					// cout << "here 1" << endl;
					if(s2.empty() || s2.top() > v[j]) {
						// cout << s2.top() << " " << v[j] << endl;
						posible = false;
						// cout << "here 3" << endl;
						break;
					}
					s1.push(s2.top());
					// cout << s2.top() << endl;
					s2.pop();
					if(s1.top() == v[j]) {
						// cout << "here 2" << endl;
						break;
					}
				}
				if(s1.size() > m) {
					posible = false;
				}
				else {
					s1.pop();
				}
			}
			else {
				if(s1.top() == v[j]) {
					s1.pop();
				}
				else {
					posible = false;
				}
			}	
		}

		if(posible) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

	return 0;
}