#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int k,n;
	cin >> t;
	while(t--){
		cin >> k >> n;
		cout << k << " " << (n*(n+3))/2 << endl;
	}
	return 0;
}
