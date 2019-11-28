#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if(k==0) cout << 1 << endl;
	else{
		if(k>(n/2)) cout << n-k << endl;
		else cout <<k << endl;
	}
	return 0;
}
