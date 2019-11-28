#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,ans;
	int L,v,l,r;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> L >> v >> l >> r;
		ans=(l-1)/v;
		ans+=(L/v)-(r/v);
		cout << ans << endl;
	}
	return 0;
}
