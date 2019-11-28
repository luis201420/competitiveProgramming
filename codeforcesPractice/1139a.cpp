#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int n,v,res=0;
	cin >> n >> s;
	for(int i=0;i<s.size();i++){
		v=s[i]-'0';
		if(v%2==0)res+=(i+1);
	}
	cout << res << endl;
	return 0;
}
