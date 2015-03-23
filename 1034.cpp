#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>

//#define DEBUG


using namespace std;

const int MINNUM = 2;
vector<int> pre;
vector<int> bingNum;

class Record{
public:
	string a;
	string b;
	int weight;
	Record(string tmp1, string tmp2, int tmp3):a(tmp1), b(tmp2), weight(tmp3){};
};

class intRecord {
public:
	int a;
	int b;
	intRecord(int tmp1, int tmp2):a(tmp1), b(tmp2){};
};

class Gang{
public:
	string head;
	int num;
	Gang(string tmp1, int tmp2):head(tmp1), num(tmp2){};
};

bool cmp(const Gang &lhs, const Gang &rhs) {
	return lhs.head < rhs.head;
}

int findRoot(int a) {
	int cur = a;
	while(cur != pre[cur]) {
		cur = pre[cur];
	}
	return cur;
}

void merge(int a, int b) {
	int ra = findRoot(a), rb = findRoot(b);
	if(ra == rb)
		return;
	if(bingNum[ra] < bingNum[rb]) {
		pre[ra] = rb;
	}
	else {
		pre[rb] = ra;
		if(bingNum[ra] == bingNum[rb])
			bingNum[ra]++;
	}
}


int main(int argc, char *argv[]) {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
#endif
	int N, K;
	scanf("%d%d", &N, &K);
	vector<Record> records;
	set<string> s;
	for(int i = 0; i < N; ++i) {
		string tmp1, tmp2;
		int tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		records.push_back(Record(tmp1, tmp2, tmp3));
		s.insert(tmp1);
		s.insert(tmp2);
	}
	map<string, int> name2id;
	map<int, string> id2name;
	int i = 0;
	for(set<string>::iterator iter = s.begin(); iter != s.end(); ++iter, ++i) {
		name2id[ (*iter) ] = i;
		id2name[ i ] = (*iter);
	}
	int num = s.size();
	vector<int> gangW(num, 0);
	vector<intRecord> intRecords;

	for(int i = 0; i < records.size(); ++i) {
		int tmp1 = name2id[ records[i].a ], tmp2 = name2id[ records[i].b ];
		//if(tmp1 == tmp2)
		//	continue;
		gangW[tmp1] += records[i].weight;
		gangW[tmp2] += records[i].weight;
		intRecords.push_back(intRecord(tmp1, tmp2));
	}

	// bing cha
	for(int i = 0; i < num; ++i)
		pre.push_back(i);
	for(int i = 0; i < num; ++i)
		bingNum.push_back(1);

	for(int i = 0; i < intRecords.size(); ++i) {
		merge(intRecords[i].a, intRecords[i].b);
	}

	map< int, vector<int> > links;
	set<int> ids;
	for(int i = 0; i < num; ++i) {
		int id =  findRoot(i);
		links[ id ].push_back(i);
		ids.insert( id );
	}
	vector<Gang> result;
	for(set<int>::iterator iter = ids.begin(); iter != ids.end(); ++iter) {
		int id = *iter;
		if(links[id].size() <= MINNUM)
			continue;
		int sum = 0;
		for(int i = 0; i < links[id].size(); ++i) {
			sum += gangW[ links[id][i] ];
		}
		if(sum / 2 <= K)
			continue;
		int head = 0;
		for(int i = 0; i < links[id].size(); ++i) {
			if(gangW[ links[id][i] ] > gangW[ links[id][head] ]) {
				head = i;
			}
		}
		result.push_back( Gang( id2name[ links[id][head] ], links[id].size() ) );
	}

	sort(result.begin(), result.end(), cmp);
	cout << result.size() << endl;

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i].head << " " << result[i].num << endl;
	}


	return 0;
}