#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 4000000000;

int main(){
	char s,e;
	cin >> s >> e;
	ll m,si,ei;
	cin >> m;
	
	if(s==94)si=0;
	if(s==62)si=1;
	if(s==118)si=2;
	if(s==60)si=3;

	if(e==94)ei=0;
	if(e==62)ei=1;
	if(e==118)ei=2;
	if(e==60)ei=3;

	//cerr << si << " " << ei << "\n";

	int a1 = (si+m)%4;
	int a2 = (si+MAX-m)%4;

	if(a1 == ei && a2 == ei)cout << "undefined";
	else if(a1==ei) cout << "cw";
	else if(a2==ei) cout << "ccw";
	else cout << "undefined";
	cout << "\n";
	return 0;
}
