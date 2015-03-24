#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int np, ng;
	scanf("%d%d", &np, &ng);
	vector<int> w(np, 0);
	for(int i = 0; i < np; ++i) {
		scanf("%d", &w[i]);
	}
	vector<int> order(np, 0);
	for(int i = 0; i < np; ++i) {
		scanf("%d", &order[i]);
	}
	vector<vector<int> > v;
	vector<int> tmp;
	vector<int> lose;
	while(1 != order.size()) {

		tmp.clear();
		lose.clear();

		int i = 0;
		for(; i <= int(order.size())-ng;) {
			int max = -1, maxId = 0;
			for(int j = i; j < i + ng; ++j) {
				if(w[order[j]] > max) {
					maxId = order[j];
					max = w[order[j]];
				}
			}
			tmp.push_back(maxId);
			for(int j = i; j < i + ng; ++j) {
				if(order[j] != maxId)
					lose.push_back(order[j]);
			}
			i += ng;
		}

		if(i < order.size()) {
			int max = -1, maxId = 0;
			for(int j = i; j < order.size(); ++j) {
				if(w[order[j]] > max) {
					maxId = order[j];
					max = w[order[j]];
				}
			}
			tmp.push_back(maxId);
			for(int j = i; j < order.size(); ++j) {
				if(order[j] != maxId)
					lose.push_back(order[j]);
			}
		}

		v.push_back(lose);
		order = tmp;
	}	

	v.push_back(vector<int>(1, order[0]));	
	
	vector<int> result(np, 0);
	int rank = 1;
	for(int i = v.size() - 1; i >= 0; --i) {
		for(int j = v[i].size() - 1; j >= 0; --j) {
			result[ v[i][j] ] = rank;
		}
		rank += v[i].size();
	}

	if(0 != result.size())
		printf("%d", result[0]);
	for(int i = 1; i < result.size(); ++i) {
		printf(" %d", result[i]);
	}
	printf("\n");
	
	return 0;
}