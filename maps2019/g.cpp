#include <bits/stdc++.h>

using namespace std;

int n,m,cont;
vector<vector<int>> adj;

int main(){
	string s,a;
	map<string,int> ids;
	vector<vector<string>> rel;
	int c,f;
	cin >> n >> m;
	rel.assign(n,vector<string>());
	f=0;
	for(int i=0;i<n;i++){
		cin >> s >> c ;
		ids[s]=i;
		for(int j=0;j<c;j++){
			cin >> a;
			if(a!=s)rel[i].push_back(a);
			else f++;
		}
	}
	if(f==m){
		cout << "FALSE ALARM" << endl;
		return 0;
	}
	adj.assign(n,vector<int>());
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<rel[i].size();j++){
			adj[i].push_back(ids[rel[i][j]]);
			indegree[ids[rel[i][j]]]++;
		}
	}
	int cont1,cont2;
	cont1=cont2=0;
	for(int i=0;i<n;i++){
		cont1+=rel[i].size();
		cont2+=indegree[i];
	}
	if(cont1==cont2) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;

	return 0;
}
