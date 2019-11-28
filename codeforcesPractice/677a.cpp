#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,h,v,ans=0;
	cin >> n >> h;
	for(int i=0;i<n;i++){
		cin >> v;
		if(v>h)ans+=2;
		else ans++;
	}
	cout << ans << "\n";
	return 0;
}
