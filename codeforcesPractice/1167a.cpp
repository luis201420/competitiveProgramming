#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n;
	string s;
	bool ver;
	while(t--){
		cin >> n >> s;
		ver=0;
		for(int i=0;i<=n-11;i++){
			if(s[i]=='8')ver=1;
		}
		if(ver && n >= 11)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
