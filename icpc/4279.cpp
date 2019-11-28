#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,res,d;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		d=n;
		res=0;
		for(int j=1;j<=n;j++){
			res+=(j*d);
			d--;
		}
		cout <<i <<": "<<n << " "<< res << endl;
	}
	return 0;
}
