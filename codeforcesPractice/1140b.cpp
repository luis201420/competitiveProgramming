#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n;
	string s;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		if(s[0]=='>' || s[n-1]=='<'){
			cout << 0 << endl;
			continue;
		}
		int i=0;
		while(i<n && s[i]=='<')i++;
		int j=n-1;
		while(j>=0 && s[j]=='>')j--;
		cout << min(i,n-(j+1)) << endl;
	}
	return 0;
}
