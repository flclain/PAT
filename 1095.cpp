#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int n, k, carNum=-1;

struct record{
	string id;
	int time;
	bool state;
}rec[10009];

struct car{
	string name;
	vector<int>start;
	vector<int>end;
	int total;
	car(){
		total=0;
	}
}cars[20010];

bool cmp(record a, record b){
	if(a.id!=b.id) return a.id<b.id;
	else{
		return a.time<b.time;
	}
}

vector<record> format;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	int h,m,s;
	char state[10];
	for(int i=0; i<n; i++){
		cin>>rec[i].id;
		scanf("%d:%d:%d %s", &h, &m, &s, state);
		rec[i].time=h*3600+m*60+s;
		if(state[0]=='i') { 
			rec[i].state=true;
		}
		else 
			rec[i].state=false;
	}

	sort(rec, rec+n, cmp);

	for(int i=0; i<n-1; i++ ){
		if(rec[i].id!=rec[i+1].id){
			i++;
		}
		if(rec[i].state==true && rec[i+1].state==false){
			format.push_back(rec[i]);
			format.push_back(rec[i+1]);
		}else if(rec[i].state==true && rec[i+1].state==true) i++;
		else if(rec[i].state==false && rec[i+1].state==false)i+=2;
		else i++;
	}

	string lastname="aa";

	for(int i=0; i<format.size()-1; i+=2){
		if(format[i].id!=lastname){
			carNum++;
			lastname=format[i].id;
			cars[carNum].name=format[i].id;
			cars[carNum].start.push_back(format[i].time);
			cars[carNum].end.push_back(format[i+1].time);
			cars[carNum].total+=(format[i+1].time-format[i].time);
		}
		else{
			cars[carNum].start.push_back(format[i].time);
			cars[carNum].end.push_back(format[i+1].time);
			cars[carNum].total+=(format[i+1].time-format[i].time);
		}
	}

	int point, sum=0;
	for(int i=0; i<k; i++){
		sum=0;
		scanf("%d:%d:%d", &h, &m, &s);
		point=3600*h+60*m+s;
		for(int i=0; i<=carNum; i++){
			for(int j=0; j<cars[i].start.size(); j++){
				if(point>=cars[i].start[j] && point<=cars[i].end[j]){
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}

	int maxtime=-1;
	for(int i=0; i<=carNum; i++){
		if(cars[i].total>maxtime){
			maxtime=cars[i].total;
		}
	}

	for(int i=0; i<=carNum; i++){
		if(cars[i].total==maxtime){
			cout<<cars[i].name<<" ";
		}
	}
	printf("%02d:%02d:%02d", maxtime/3600, maxtime%3600/60, maxtime%60);

	//system("pause");
	return 0;
}

