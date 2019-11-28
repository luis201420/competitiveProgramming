#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,cont,res;
	cin >> n;
	string s;
	cin >> s;
	int j,v,aux;
	res=0;
	char c1,c2,c3;
	for(int i=0;i<s.size();i++){
		j=i+1;
		cont=1;
		while(j<s.size() && s[i]==s[j]){
			cont++;
			j++;
		}
		c1 = s[i];
		aux=i;
		i=j-1;
		v = cont/2;
		res+=v;
		if(cont&1 || j>=s.size()){
			if(c1=='R' || c1=='B')c3='G';
			if(c1=='G') c3='R';
			j=aux+1;
			while(v--){
				s[j]=c3;
				j+=2;
			}
		}
		else{
			c2=s[j];
			if((c1=='R' && c2=='G') || (c1=='G' && c2=='R'))c3='B';
			if((c1=='R' && c2=='B') || (c1=='B' && c2=='R'))c3='G';
			if((c1=='G' && c2=='B') || (c1=='B' && c2=='G'))c3='R';
			j=aux+1;
			while(v--){
				s[j]=c3;
				j+=2;
			}
		}
	}
	cout << res << endl;
	cout << s << endl;
	return 0;
}
