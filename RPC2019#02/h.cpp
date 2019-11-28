#include<bits/stdc++.h>

using namespace std;

bool ver(string a,string b){
	int n=a.size();
	if(n > b.size())return 0;
	for(int i=0;i<(b.size()-n+1);i++){
		if(b.substr(i,n)==a)return 1;
	}
	return 0;
}

int main(){
	vector<string> dic,auxL;
	int e,p;
	string s,el,pl,aux;
	cin >> s;
	cin >> e;
	bool v;
	getline(cin,el);
	while(e--){
		getline(cin,el);
		aux="";
		v=0;
		for(int i=0;i<el.size();i++){
			if(el[i]==' '){	
				if(ver(aux,s))v=1;
				auxL.push_back(aux);
				aux="";
			}
			else aux+=el[i];
		}	
		if(ver(aux,s)){v=1;}
		auxL.push_back(aux);
		if(v){
			for(int i=0;i<auxL.size();i++)dic.push_back(auxL[i]);
		}
		auxL.clear();
	}
	cin >> p;
	getline(cin,pl);
	while(p--){
		getline(cin,pl);
		v=0;
		aux="";
		for(int i=0;i<pl.size();i++){
			if(pl[i]==' '){
				/*for(int j=0;j<dic.size();j++){
					if(ver(dic[j],aux)){
						v=1;
						break;
					}
				}*/
				aux="";
			}
			else aux+=pl[i];
		}
		for(int i=0;i<dic.size();i++){
			if(ver(dic[i],aux)){
				v=1;
				break;
			}
		}
		/*for(int i=0;i<dic.size();i++){
			if(dic[i].size()>pl.size())continue;
			
			aux = pl.substr(pl.size()-dic[i].size());
			if(dic[i]==aux){v=1;break;}
		}*/
		if(v)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
