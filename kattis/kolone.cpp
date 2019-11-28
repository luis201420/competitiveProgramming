#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,t;
	string sn,sm;
	cin >> n >> m;
	cin >> sn >> sm;
	cin >> t;
	string res(n+m,' ');
	int aux=t,pos;
	reverse(sn.begin(),sn.end());
	for(int i=n-1;i>=0;i--){
		pos=(aux>=0)?aux+i : i+0;
		if(aux>=m)pos=m+i;
		res[pos]=sn[i];
		aux--;
	}
	aux=t;
	for(int i=0;i<m;i++){
		pos=n+i;
		pos=(aux>=0)?pos-aux : pos;
		if(aux>=n)pos=i;
		res[pos]=sm[i];
		aux--;
	}
	cout << res << endl;
	return 0;
}
