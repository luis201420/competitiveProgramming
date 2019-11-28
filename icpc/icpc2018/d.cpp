#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool ver,vp;
	string s,p1,p2;
	set<string> cont;
	cin >> n;
	while(n--){
		cin >> s;
		ver=vp=1;
		p1=p2="";
		for(int i=0;i<s.size();i++){
			if(s[i]=='+')ver=0;
			else if(s[i]=='@'){ver=1;vp=0;}
			else if(ver){
				if(vp && s[i]!='.')
					p1+=s[i];
				else if(!vp)
					p2+=s[i];
			}
		}
		cont.insert(p1+p2);
		//cout << p1 << p2 << endl;
	}
	cout << cont.size() << endl;
	return 0;
}
