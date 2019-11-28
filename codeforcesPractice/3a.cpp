#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	int d1 = s[0]-t[0];
	int d2 = s[1]-t[1];
	int m = max(abs(d1),abs(d2));
	char c1 = d1>0? 'L' : 'R';
	char c2 = d2>0? 'D' : 'U';
	cout << m << endl;
	for(int i=0;i<min(abs(d1),abs(d2));i++){
		cout << c1 << c2 << endl;
	}
	d1=abs(d1);d2=abs(d2);
	if(d1<d2)c1=c2;
	for(int i=0;i<abs(d1-d2);i++){
		cout << c1 << endl;
	}
	return 0;
}
