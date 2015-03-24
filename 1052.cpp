#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

class Node
{
public:
	int val;
	int adr;
	int next;
	bool operator < (const Node &rhs) const {
		return val < rhs.val;
	}
};

int main(int argc, char const *argv[])
{
	int n, root;
	cin >> n >> root;
	vector<Node> v;
	Node node;
	Node m[100010];
	for(int i = 0; i < n; ++i) {
		cin >> node.adr >> node.val >> node.next;
		if(node.adr < 0)
			continue;
		m[node.adr] = node;
	}
	int cur = root;
	while(cur != -1) {
		v.push_back(m[cur]);
		cur = m[cur].next;
	}
	sort(v.begin(), v.end());
	if(v.size() == 0) {
		printf("0 -1\n");
		return 0;
	}
	cout << v.size() << " ";
	printf("%.05d\n", v[0].adr);
	for(int i = 0; i < v.size() - 1; ++i) {
		printf("%.05d %d %.05d\n", v[i].adr, v[i].val, v[i+1].adr);
	}
	printf("%.05d %d -1\n", v[v.size()-1].adr, v[v.size()-1].val);
	return 0;
}