#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    vector<double> v1(1001, 0);
    vector<double> v2(1001, 0);
    int k;
    double a;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%lf", &k, &a);
        v1[k] = a;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%lf", &k, &a);
        v2[k] = a;
    }
    int count = 0;
    for(int i = 0; i <= 1000; ++i) {
        v1[i] += v2[i];
        if(v1[i] != 0)
            ++count;
    }
    printf("%d", count);
    for(int i = 1000; count > 0 && i >= 0 ; --i) {
        if(v1[i] == 0)
            continue;
        --count;
        printf(" %d %.1f", i, v1[i]);
    }
    printf("\n");
    return 0;
}
