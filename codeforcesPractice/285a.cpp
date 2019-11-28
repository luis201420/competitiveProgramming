#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,k,p;
	cin >> n >> k;
	p=n;
	if(k>0){
		cout << p << " ";
		p--;
	}
	for(int i=0;i<(k-1);i++){
		if(i!=0)cout << " ";
		cout << p--;
	}
	if(k>0)cout << " ";
	for(int i=1;i<=p;i++){
		if(i!=1)cout << " ";
		cout << i;
	}
	cout << "\n";
	return 0;
}
