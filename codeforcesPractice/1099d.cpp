#include <bits/stdc++.h>

using namespace std;

vector<long long> sn;
vector<vector<long long>> g;
long long res;
bool ver;

void dfs(long long ini,long long c){
	if(sn[ini]!=-1){
		if(c>sn[ini])ver=true;
		res+=sn[ini]-c;	
	}
	for(int i=0;i<g[ini].size();i++){
		if(sn[ini]!=-1)dfs(g[ini][i],sn[ini]);
		else dfs(g[ini][i],c);
	}
}

int main(){
	long long n,p,s;	
	cin >> n;
	g.assign(n,vector<long long>());
	sn.assign(n,-1);
	for(int i=1;i<n;i++){
		cin >> p;
		g[p-1].push_back(i);
	}
	for(int i=0;i<n;i++){
		cin >> s;
		sn[i]=s;
	}
	res=0;
	ver=false;
	dfs(0,0);
	if(ver)cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
