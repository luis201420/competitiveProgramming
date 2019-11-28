#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> cont(26,0);
	int t=0;
	for(int i=0;i<s.size();i++){
		if(cont[s[i]-'a']==0)t++;
		cont[s[i]-'a']++;
	}
	if(t<=2)cout << 0 << endl;
	else{
		sort(cont.begin(),cont.end());
		int ans=0,aux=t-2;
		int i=0;
		while(i<26 && cont[i]==0)i++;
		for(int k=0;k<aux;k++,i++)ans+=cont[i];
		cout << ans << endl;
	}
	return 0;
}
