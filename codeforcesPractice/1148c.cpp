#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n ;
	vector<int> ns(n),pos(n+1,-1);
	for(int i=0;i<n;i++){
		cin >> ns[i];
		pos[ns[i]]=i;
	}
	vector<pair<int,int>> sol;
	
	for(int i=1;i<=(n/2);i++){
		if(pos[i]<(n/2)){
			int j=(n/2)+1;
			for(;j<=n;j++){
				if(pos[j]>=(n/2))break;
			}
			if(j>n)break;
			sol.push_back({pos[i],pos[j]});
			swap(ns[pos[i]],ns[pos[j]]);	
			swap(pos[i],pos[j]);
		}
	}
	int aux;
	for(int i=0;i<n;i++){
		if(ns[i]!=(i+1)){
			sol.push_back({i,pos[i+1]});
			pos[ns[i]]=pos[i+1];
			ns[pos[i+1]]=ns[i];
		}
	}
	cout << sol.size() << endl;
	for(int i=0;i<sol.size();i++){
		cout << (sol[i].first)+1 << " " << (sol[i].second)+1 << endl;
	}
	return 0;
}
