#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,res;
	int k,cont1,cont2,cont3;
	cin >> s >> k;
	cont1=cont2=cont3=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?')cont1++;
		else if(s[i]=='*')cont2++;
		else cont3++;
	}
	if(k<cont3 && (cont1+cont2)<(cont3-k))cout << "Impossible";
	else{
		res="";
		if(k<cont3){
			for(int i=0;i<s.size();i++){
				if((s[i]=='?' || s[i]=='*')){
					if(cont3>k){
					res=res.substr(0,res.size()-1);
					cont3--;
					}
				}
				else{
					res+=s[i];
				}
			}
			cout << res;
		}
		else{
			for(int i=0;i<s.size();i++){
				if(s[i]=='?')continue;
				else if(s[i]=='*'){
					res+=string(k-cont3,res[res.size()-1]);
					cont3=k;
				}
				else res+=s[i];
			}
			if(res.size()==k)cout << res;
			else cout << "Impossible";
		}
	}
	cout << endl;
	return 0;
}
