#include <bits/stdc++.h>

using namespace std;

double dist(pair<double,double> a , pair<double,double> b){
	double d1 = abs(a.first-b.first);
	double d2 = abs(a.second-b.second);
	return sqrt(( d1*d1 )+( d2*d2 ));
}

vector<vector<int>> adj;
vector<pair<double,double>> gophers;
vector<bool> visited;
vector<int> match;

bool aug(int ini){
	if(visited[ini]) return 0;
	visited[ini] = 1;
	for(int i=0;i<adj[ini].size();i++){
		int r=adj[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m,s,v,res;
	double v1,v2,d;
	while(cin >> n >> m >> s >> v){
		for(int i=0;i<n;i++){
			cin >> v1 >> v2;
			gophers.push_back({v1,v2});
		}
		adj.assign(n,vector<int>());
		for(int j=0;j<m;j++){
			cin >> v1 >> v2;
			for(int i=0;i<gophers.size();i++){
				d=dist(make_pair(v1,v2),gophers[i]);
				if(d <= (s*v)) adj[i].push_back(j);
			}
		}
		res=0;
		match.assign(m,-1);
		for(int i=0;i<n;i++){
			visited.assign(n,0);
			res+=aug(i);
		}
		cout << n-res << endl;
		gophers.clear();
	}
	return 0;
}
