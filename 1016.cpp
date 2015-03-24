#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Record {
	int mo;
	int dd;
	int hh;
	int mm;
	bool online;
	void printRecord() {
		printf("%02d:%02d:%02d ", dd, hh, mm);		
	}
};

struct Call {
	Record in;
	Record out;
	double cost;
	int len;
};

bool cmp(const Record &lhs, const Record &rhs) {
	if(lhs.mo == rhs.mo) {
		if(lhs.dd == rhs.dd) {
			if(lhs.hh == rhs.hh) {
				return lhs.mm < rhs.mm;
			}
			else {
				return lhs.hh < rhs.hh;
			}
		}
		else {
			return lhs.dd < rhs.dd;
		}
	}
	else {
		return lhs.mo < rhs.mo;
	}
}

Call getCost(const Record &callIn, const Record &callout, int *price) {
	Call call;
	Record in = callIn, out = callout;
	call.in = in;
	call.out = out;
	int cost = 0;
	int len = 0;
	while( !(in.dd == out.dd && in.hh == out.hh && in.mm == out.mm) ) {
		cost += price[in.hh];
		in.mm++;
		len++;
		if(60 == in.mm) {
			in.mm = 0;
			in.hh++;
		}
		if(24 == in.hh) {
			in.hh = 0;
			in.dd++;
		}
	}
	call.cost = double(cost)/100.0;
	call.len = len;
	return call;
}


const string onLineType = "on-line";

int main(int argc, char *argv[]) {
	// get input

	int price[24];
	for(int i = 0; i < 24; ++i)
		scanf("%d", &price[i]);
	
	int n;
	scanf("%d", &n);
	string tmpName;
	string tmpType;
	map<string, vector<Record> > records;
	for(int i = 0; i < n; ++i) {
		cin >> tmpName;
		Record record;
		scanf("%d:%d:%d:%d", &record.mo, &record.dd, &record.hh, &record.mm);
		cin >> tmpType;
		record.online = tmpType == onLineType;
		records[tmpName].push_back(record);
	}

	vector<string> names;
	for(map<string, vector<Record> >::iterator it = records.begin(); it != records.end(); ++it) {
		names.push_back(it->first);
	}
	sort(names.begin(), names.end());
	for(int i = 0; i < names.size(); ++i) {
		vector<Record> &v = records[ names[i] ];
		sort(v.begin(), v.end(), cmp);

		// stack<int> s;
		vector<Call> calls;
		for(int ii = 0; ii < v.size() - 1; ++ii) {

			if(v[ii].online == true && v[ii+1].online == false)
				calls.push_back( getCost(v[ii], v[ii+1], price) );
			// if(s.empty()) {
			// 	if(false == v[ii].online)
			// 		continue;
			// 	else 
			// 		s.push(ii);
			// }
			// else {
			// 	if(true == v[ii].online) {
			// 		s.push(ii);
			// 	}
			// 	else {
			// 		calls.push_back( getCost(v[s.top()], v[ii], price) );
			// 		s.pop();
			// 	} 
			// }
		}

		if(0 == calls.size()) 
			continue;

		cout << names[i];
		printf(" %02d\n", calls[0].in.mo);
		double totalCost = 0;
		for(int ii = 0; ii < calls.size(); ++ii) {
			calls[ii].in.printRecord();
			calls[ii].out.printRecord();
			printf("%d $%.2f\n", calls[ii].len, calls[ii].cost);
			totalCost += calls[ii].cost;
		}
		printf("Total amount: $%.2f\n", totalCost);
	}


}