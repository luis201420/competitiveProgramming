#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	if(n<m){
		cout << "-1\n";
	}
	else{
		int ans=((n+(n&1))/2);
		while((ans%m)!=0)ans++;
		cout << ans << "\n";
	}
	return 0;
}
