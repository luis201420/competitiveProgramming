#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,w,a,b,t;
	while(cin >> w){
		cin >> n;
		t=0;
		while(n--){
			cin >> a >> b;
			t+=(a*b);
		}
		cout << t/w << endl;
	}
	return 0;
}
