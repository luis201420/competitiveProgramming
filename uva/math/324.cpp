#include <bits/stdc++.h>

using namespace std;

string sum(string a,string b){
	
	int res,aux;
	string ans = "";
	res=0;

	for(int i=0;i<min(a.size(),b.size());i++){
		aux=(a[a.size()-i-1]-'0')+(b[b.size()-i-1]-'0')+res;
		ans=to_string(aux%10)+ans;
		res=aux/10;
	}

	if(a.size()>b.size()){
		ans=sum(a.substr(0,a.size()-b.size()),to_string(res)) + ans;
	}
	else if(a.size()<b.size()){
		ans=sum(b.substr(0,b.size()-a.size()),to_string(res)) + ans;
	}
	else{
		if(res>0)ans=to_string(res)+ans;
		return ans;
	}
}

void multi(string &fac,int n){
	string sumT="0";
	int aux,res,cont=0;
	string ans;
	while(n){
		res=0;
		ans="";
		for(int i=fac.size()-1;i>=0;i--){
			aux=(fac[i]-'0')*(n%10)+res;
			ans=to_string(aux%10)+ans;
			res=aux/10;
		}
		if(res>0) ans=to_string(res)+ans;
		ans+=string(cont,'0');
		sumT = sum(sumT,ans);
		n-=(n%10);
		n/=10;
		cont++;
	}
	fac=sumT;
}


int main(){
	int n;
	string fac,aux;
	vector<int> cont;
	while(cin>>n){
		if(n==0)break;

		fac="1";
		
		for(int i=2;i<=n;i++){
			multi(fac,i);
		}

		cout << n << "! --\n";
		cont.assign(10,0);

		for(int i=0;i<fac.size();i++){
			cont[fac[i]-'0']++;
		}
		for(int i=0;i<5;i++){
			if(i>0)cout << " ";
			cout << "   (" << i << ")" << string(5-(to_string(cont[i])).size(),' ')<< cont[i];
		}
		cout << endl;
		for(int i=5;i<cont.size();i++){
			if(i>5)cout << " ";
			cout << "   (" << i << ")" << string(5-(to_string(cont[i])).size(),' ')<< cont[i];
		}
		cout << endl;
	}
	return 0;
}
