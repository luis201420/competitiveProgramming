#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,res,aux;
	cin >> t;
	vector<int> ns;
	while(t--){
		cin >> n;
		
		ns.resize(3*n);
		
		for(int i=0;i<(3*n);i++)
			cin >> ns[i];
		
		sort(ns.begin(),ns.end(),greater<int>());
		
		res=0;aux=n;
		for(int i=1;i<(3*n)-1&&aux;i+=2){
			res+=ns[i];
			aux--;
		}
		cout << res << endl;
	}
	return 0;
}
