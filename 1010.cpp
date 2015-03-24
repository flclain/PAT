#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long lint;

int trans(char c) {
	if(c >= '0' && c <= '9')
		return c - '0';
	else if(c >= 'a' && c <= 'z')
		return c - 'a' + 10; 
	return 0;
}

lint s2int(string s, int radix) {
	lint result = 0;
	for(int i = 0; i < s.size(); ++i) {
		result = result * radix + trans(s[i]);
		if(result < 0) {
			return -1;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	string s1;
	string s2;
	int tag, radix;
	cin >> s1 >> s2 >> tag >> radix;
	if(2 == tag)
		swap(s1, s2);
	lint a = 0;
	for(int i = 0; i < s1.size(); ++i) {
		a = a * radix + trans(s1[i]);
	}
	int minRadix = -1;
	for(int i = 0; i < s2.size(); ++i) {
		minRadix = max( minRadix, trans(s2[i]) );
	}
	++minRadix;
	lint cur = 0, pre = -1;
	
	lint low = max(minRadix, 2), high = a + 1, mid;

	lint result = -1;
	while(low <= high) {	
		mid = (low + high) / 2;
		cur = s2int(s2, mid);
		if( cur >= a || -1 == cur ){
			if( cur == a && (mid < result || -1 == result) )
				result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	if(result != -1){
		cout << result << endl;
	}
	else
		cout << "Impossible" << endl;

	return 0;
}