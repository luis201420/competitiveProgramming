#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,res=1e9,cont;
	cin >> n;
	string s,p="BGR",aux,auxs,sn;
	cin >> s;
	if(n%3!=0){
		s+=string(3-(n%3),'-');
	}
	do{
		//cerr << p << endl;
		cont = 0;
		auxs ="";
		for(int i=0;i<s.size();i+=3){
			aux=s.substr(i,3);
			if(aux[0] !='-' && aux[0]!=p[0])cont++;
			if(aux[1] !='-' && aux[1]!=p[1])cont++;
			if(aux[2] !='-' && aux[2]!=p[2])cont++;
			auxs+=p;
		}
		if(res>cont){
		       	res = cont;
			sn = auxs;
		}
	}while(next_permutation(p.begin(),p.end()));
	cout << res << endl;
	cout << sn.substr(0,n) << endl;
	return 0;
}
