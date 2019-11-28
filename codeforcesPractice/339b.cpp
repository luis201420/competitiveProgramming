#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,m,a,res=0,aux=1;
	cin >> n >> m;
	while(m--){
		cin >> a;
		if(aux<=a)res+=(a-aux);
		else res+=((n-aux)+a);
		aux=a;
	}
	cout << res << endl;
	return 0;
}
