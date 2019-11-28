#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int blue,red;
	string s;
	cin >> n >> s;
	blue=red=0;
	string ans="";
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			if(blue<red){
				ans+="1";
				blue++;
			}
			else{
				ans+="0";
				red++;
			}
		}
		else{
			if(blue<red){
				ans+="0";
				red--;
			}
			else{
				ans+="1";
				blue--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
