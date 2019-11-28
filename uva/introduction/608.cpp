#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> cont;
	vector<char> ver;
	char v,aux;
	int t;
	cin >> t;
	string l,r,o;
	while(t--){
		cont.assign(12,0);
		ver.assign(12,'-');
		for(int j=0;j<3;j++){
			cin >> l >> r >> o;
			if(o == "even")v='a';
			if(o == "up") v='u';
			if(o == "down")v='d';
			for(int i=0;i<l.size();i++){
				cont[l[i]-'A']++;
				cont[r[i]-'A']++;
				if(v=='a'){
					ver[l[i]-'A']=v;
					ver[r[i]-'A']=v;
				}
				else{
					if(ver[l[i]-'A']!='a' && ver[l[i]-'A']!='w'){
						aux=(v=='u')?'<':'>';
						if(ver[l[i]-'A']=='-')ver[l[i]-'A']=aux;
						if(ver[l[i]-'A']!=aux)ver[l[i]-'A']='w';
					}
					if(ver[r[i]-'A']!=1 && ver[r[i]-'A']!=0){
						aux=(v=='u')?'>':'<';
						if(ver[r[i]-'A']=='-')ver[r[i]-'A']=aux;
						if(ver[r[i]-'A']!=aux)ver[r[i]-'A']='w';
					}
				}
			}
		}
		int resC=0,res;
		for(int i=0;i<12;i++){
			if(ver[i]=='<' || ver[i]=='>'){
				if(cont[i]>resC){
					res=i;resC=cont[i];
				}
			}
			//cerr << ver[i] << endl;
		}
		cout << char('A'+res) << " is the counterfeit coin and it is ";
		if(ver[res]=='<') cout << "heavy.";
		else cout << "light.";
		cout << endl;
		
	}
	return 0;
}
