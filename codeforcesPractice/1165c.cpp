#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	string res = "";
	for(int i=0;i<n;i++){
		if(res.size()%2==0 || (res.size()%2==1 && s[i]!=res[res.size()-1]))
			res+=s[i];
	}
	if(res.size()%2==1)res=res.substr(0,res.size()-1);
	cout << s.size()-res.size()<<endl;
	cout << res << endl;
	return 0;
}
