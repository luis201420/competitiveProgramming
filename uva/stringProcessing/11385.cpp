#include <bits/stdc++.h>

using namespace std;

map<int,int> ord;

void onlyLetters(string &a){
	for(int i=0;i<a.size();i++){
		if(!isalpha(a[i]) || !isupper(a[i])){
			a.erase(a.begin()+i);
			i--;
		}
	}
}

int mising(vector<int> f){
	sort(f.begin(),f.end());
	int aux1=1,aux2=1,aux3,cont=0,pos=0;

	for(int i=0;i<f.size();i++){
		while(f[i]!=aux2){
			cont++;
			aux3=aux2;
			aux2+=aux1;
			aux1=aux3;
			pos++;
		}
		ord[f[i]]=pos;
		aux3=aux2;
		aux2+=aux1;
		aux1=aux3;
		pos++;
	}

	return cont;
}

int main(){
	int t,n,v,space;
	vector<int> Nfib;
	string line,res;
	cin>>t;
	while(t--){
		Nfib.clear();
		cin>>n;
		space=n;
		while(n--){
			cin>>v;
			Nfib.push_back(v);
		}
		getline(cin,line);
		getline(cin,line);
		
		onlyLetters(line);
		space += mising(Nfib);
		res = string(space,' ');

		for(int i=0;i<Nfib.size();i++){
			res[ord[Nfib[i]]]=line[i];
		}

		cout<<res<<endl;
		ord.clear();
	}
	return 0;
}
