#include <bits/stdc++.h>

#define F(n,m) (n*(n+1)*m*(m+1))/4

using namespace std;

int main(){

	int n,v;
	map<int,int> cont;
	cin >> n;
	string s,aux;
	cin >> s;
	aux="";
	for(unsigned i=0;i<s.size();i++){
		if(s[i]!=',')aux+=s[i];
		else{
			cont[atoi(aux.c_str())]++;
			aux="";
		}
	}
	cont[atoi(aux.c_str())]++;

	vector<int> conj;
	map<int,int>::iterator it;
	for(it=cont.begin();it!=cont.end();it++){
		if(it->second > 1) conj.push_back((it->second)-1);
	}
	int res = 0;
	for(unsigned i=0;i<conj.size();i++){
		for(unsigned j=i+1;j<conj.size();j++){
			res+=F(conj[i],conj[j]);
		}
	}

	cout << res;

	return 0;
}
