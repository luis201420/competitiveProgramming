#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,a="";
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='a')a+=s[i];
	}
	if(a.size()&1)cout << ":(";
	else{
		if(a.size()==0)cout << s;
		else{
			string p1=a.substr(0,a.size()/2);
			string p2=a.substr(a.size()/2);
			if(p1!=p2) cout << ":(";
			else{
				int pos = s.size()-(a.size()/2);
				bool v=0;
				for(int i=pos;i<s.size();i++){
					if(s[i]=='a')v=1;
				}
				if(v)cout << ":(";
				else cout << s.substr(0,pos);
			}
		}
	}
	cout << endl;
	return 0;
}
