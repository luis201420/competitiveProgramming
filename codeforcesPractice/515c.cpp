#include <bits/stdc++.h>

using namespace std;

const string val[10]={"","","2","3","322","5","53","7","7222","7332"};

int main(){
	int n;
	string s,ans="";
	cin >> n >> s;
	for(int i=0;i<n;i++){
		ans+=val[s[i]-'0'];
	}
	sort(ans.begin(),ans.end(),greater<char>());
	cout << ans << "\n";
	return 0;
}
