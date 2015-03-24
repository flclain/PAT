#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int t[2000];
	memset(t, 0, sizeof(t));
	char str[11000];
	cin.getline(str, 10010);
	char s[11000];
	cin.getline(s, 10010);
	for(unsigned int i = 0; '\0' != s[i]; ++i) {
		t[s[i]] = 1;
	}
	for(int i = 0; str[i] != '\0'; ++i) {
		if(0 == t[str[i]])
			printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}