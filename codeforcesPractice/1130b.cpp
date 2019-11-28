#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	vector<pair<int,int>> cont;
	cin >> n;
	cont.assign(n+1,pair<int,int>(-1,-1));
	for(int i=0;i<2*n;i++){
		cin >> v;
		if(cont[v].first == -1) cont[v].first = i;
		else{
			if(cont[v].first > i){
				swap(cont[v].first,cont[v].second);
				cont[v].first=i;
			}
			else
				cont[v].second=i;
		}
	}
	//for(int i=1;i<=n;i++)cerr << cont[i].first << " " << cont[i].second << endl;
	long long res = cont[1].first + cont[1].second;
	for(int i=2;i<=n;i++){
		res+=abs(cont[i].first-cont[i-1].first);
		res+=abs(cont[i].second-cont[i-1].second);
	}
	cout << res << endl;
	return 0;
}
