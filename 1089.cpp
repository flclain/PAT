#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

void printV(const vector<int> v) {
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); ++i) 
		printf(" %d", v[i]);
	printf("\n");
}

bool MergeSort(vector<int> &oriV, vector<int> &curV) {
	


}

bool insertionSort(const vector<int> &oriV, const vector<int> &curV) {
	vector<int> v(oriV);

	if(oriV.size() == 1) {
		printf("Insertion Sort\n");
		printV(v);
		return true;
	}

	bool result = false;

	for(int i = 1; i < oriV.size(); ++i) {
		// move one step;
		int j = i - 1;
		for(; j >= 0; --j) {
			if(v[i] > v[j])
				break;
		}
		int tmpI = v[i];
		++j;
		for(int k = i; k >= j + 1; --k) {
			v[k] = v[k-1];
		}
		v[j] = tmpI;

		// check equal
		if(result) {
			printf("Insertion Sort\n");
			printV(v);
			break;
		}
		if(curV == v) {
			result = true;
		}
	}
	return result;
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	vector<int> oriV(N, 0);
	vector<int> curV(N, 0);
	for(int i = 0; i < N; ++i) 
		scanf("%d", &oriV[i]);
	for(int i = 0; i < N; ++i)
		scanf("%d", &curV[i]);
	if( !insertionSort(oriV, curV) )
		MergeSort(oriV, curV);
	return 0;
}