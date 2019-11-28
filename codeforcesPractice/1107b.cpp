#include<bits/stdc++.h>

using namespace std;

int main(){
	long long q,k,n;
	cin >> q;
	while(q--){
		cin >> k >> n;
		cout << n+((k-1)*9) << endl;
	}
	return 0;
}
