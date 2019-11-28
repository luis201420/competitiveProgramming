#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	k = 240-k;
	int i;
	for(i=1;i<=n;i++){
		if(k<(i*5))break;
		k-=(i*5);
		
	}
	cout << i-1 << endl;
	return 0;
}
