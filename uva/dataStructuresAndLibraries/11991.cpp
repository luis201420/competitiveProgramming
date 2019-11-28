#include <bits/stdc++.h>

using namespace std;

typedef int T_number;

int main(){
	map<T_number,vector<T_number>> rel;
	T_number n,m,v,k;

	while(cin >> n >> m){
		for(int i=1;i<=n;i++){
			cin >> v;
			rel[v].push_back(i);
		}
		while(m--){
			cin >> k >> v;

			if(rel[v].size()<k) cout << 0;
			else cout << rel[v][k-1];
			
			cout << endl;
		}
		rel.clear();	
	}

	return 0;
}
