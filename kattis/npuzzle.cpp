#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans=0;
	int x,y,p;
	string s;
	for(int i=0;i<4;i++){
		cin >> s;
		for(int j=0;j<4;j++){
			if(s[j]!='.'){
				p=s[j]-'A';
				x=p/4;
				y=p%4;
			}
			else continue;
			//cerr << x << " " << y << "\n";
			ans+=(abs(x-i)+abs(y-j));
		}
	}
	cout << ans << "\n";
	return 0;
}
