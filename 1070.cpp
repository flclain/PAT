#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Cake {
public:
	double _weight;
	double _price;
	double _eps;
};

bool cmp(const Cake &lhs, const Cake &rhs) {
	return lhs._eps > rhs._eps;
}

int main(int argc, char *argv[]) {
	int n, v;
	scanf("%d%d", &n, &v);
	vector<Cake> cakes(n);
	Cake tmp;
	for(int i = 0; i < n; ++i) 
		scanf("%lf", &cakes[i]._weight);
	for(int i = 0; i < n; ++i)
		scanf("%lf", &cakes[i]._price);
	vector<Cake> fcakes;
	for(int i = 0; i < n; ++i) {
		if(cakes[i]._weight != 0 && cakes[i]._price != 0) {
			cakes[i]._eps = cakes[i]._price / cakes[i]._weight;
			fcakes.push_back(cakes[i]);
		}
	}
	if(v == 0 || fcakes.size() == 0) {
		printf("0.00\n");
		return 0;
	}
	sort(fcakes.begin(), fcakes.end(), cmp);
	double result = 0;
	for(int i = 0; i < fcakes.size(); ++i) {
		if(0 == v)
			break;
		if(v >= fcakes[i]._weight) {
			result += fcakes[i]._price;
			v -= fcakes[i]._weight;
		}
		else {
			result += fcakes[i]._price * 1.0 * v / fcakes[i]._weight;
			v = 0;
		}
	}
	printf("%.2f\n", result);
	return 0;
}