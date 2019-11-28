#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,ans=0;
	bool ver;
	string s;
	
	cin >> n;

	while(n--){
		cin >> s;
		ver=1;
		for(int i=0;i<int(s.size())-1;i++){
			if(s.substr(i,2)=="CD"){
				ver=0;
			}
		}
		if(ver)	ans++;
	}
	cout << ans << "\n";
	return 0;
}
