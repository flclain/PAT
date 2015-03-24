#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <functional>
#include <cstring>
#include <stack>
#include <set>

multiset<int> s1;


using namespace std;

//  key is a positive integer no more than 10^5

const int MAXNUM = 100000;

const string pushStr = "Push";
const string popStr = "Pop";
const string midStr = "PeekMedian";

int a[MAXNUM + 1];

void update(int pos, int num) {
	if(pos <= 0)
		return;
	while(pos <= MAXNUM) {
		a[pos] += num;
		pos += pos & (pos ^ (pos - 1));
	}
}

int getSum(int pos) {
	int result = 0;
	while(pos > 0) {
		result += a[pos];
		pos -= pos & (pos ^ (pos - 1));
	}
	return result;
}

int getMid(int n) {
	int midPos = (n - 1) / 2 + 1;
	int left = 1;
	int right = MAXNUM;
	while(left <= right) {
		if(left == right)
			return left;
		int mid = (right - left) / 2 + left;
		if( getSum(mid) < midPos ) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
}

struct BinTree
{
    static const int MAXN = 100010;
    vector<int> a;

    BinTree()
    {
        a = vector<int>(MAXN,0);
    }

    int lowbit(int t)
    {
        return t&(-t);
    }

    void update(int t, int d)
    {
        while (t <= MAXN)
        {
            a[t] += d;
            t += lowbit(t);
        }
    }

    int getsum(int t)
    {
        int sum(0);
        while (t > 0)
        {
            sum += a[t];
            t -= lowbit(t);
        }
        return sum;
    }
    int find(int val, int l = 0, int h = MAXN - 1)
    {
        if (l == h)
            return l;
        int mid = (l + h) / 2;
        if (getsum(mid) < val)
        {
            //return find(val, mid, h);
            return find(val, mid + 1, h);
        }
        else
        {
            return find(val, l, mid);
        }
    }
};
BinTree tree;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	scanf("%d", &N);
	int mid = 0;
	stack<int> s;
	string action;

	char str[20];

	

	memset(a, 0, sizeof(a));

	for(int k = 0; k < N; ++k) {
		/*cin >> action;*/

		scanf("%s", &str);

		// push
		if('u' == str[1]) {
			int tmp;
			scanf("%d", &tmp);
			update(tmp, 1);
			//tree.update(tmp, 1);

			s.push(tmp);

		}
		// pop
		else if('o' == str[1]) {
			if(0 != s.size()) {
				printf("%d\n", s.top());
				update(s.top(), -1);
				//tree.update(s.top(), -1);

				s.pop();

			}
			else {
				printf("Invalid\n");
			}
		}
		// mid
		else {
			if(0 != s.size()) {
				mid = getMid(s.size());
				//mid = tree.find(  (s.size() + 1) / 2  );
				printf("%d\n", mid);
			}
			else {
				printf("Invalid\n");
			}
		}

	}

	return 0;
}