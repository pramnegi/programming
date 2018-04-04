#include <iostream>
#include <string.h>
using namespace std;
/*objective: to calculate all possible permutations of a string
approach: recursion
input: 1. no of test cases
	2. string
*/

void swp(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b= temp;
}


int flag=0;
void print(string s, int l, int r) {
	int i;
	if (l == r) {
		cout<<s<<endl;
		return;
	}
	for (i = l; i <= r; i++) {
		swp(&(s[l]), &(s[i]));
		print(s, l+1, r);
		swp(&(s[l]), &(s[i]));
	}
}


int main() {
	int t;
	string s;
	cin>>t;
	while(t--) {
    cin.clear();
    cin>>s;
	int n = s.length();
	print(s, 0, n-1);
	cout<<"-------------------------"<<endl;
    }
	return 0;
}
