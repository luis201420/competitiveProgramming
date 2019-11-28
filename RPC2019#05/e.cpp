#include <bits/stdc++.h>

using namespace std;

vector<double> values;
vector<vector<int>> adj;
vector<double> dp;

void dfs(int r){
	
	int v;
	double mt=values[r],mu;
	for(int i=0;i<adj[r].size();i++){
		v=adj[r][i];
		if(dp[v]==-1) dfs(v);
		mu=max(values[r]+(dp[v]/2.0),dp[v]);
		mt=max(mt,mu);
	}
	dp[r]=mt;
}

int main(){
	int a,b;
	int n,m;
	cin >> n >> m;
	values.resize(n);
	for(int i=0;i<n;i++){
		cin >> values[i];
	}
	adj.assign(n,vector<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a].push_back(b);
	}
	dp.assign(n,-1);
	dfs(0);
	cout << setprecision(9) << fixed;
	cout << dp[0] << endl;
	return 0;
}
