#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> degrees,ans;

int main(){
	int n,m;
	int a,b,r;
	stack<int> p;
	while(cin >> n >> m && (n+m)){
		adj.assign(n,vector<int>());
		degrees.assign(n,0);
		while(m--){
			cin >> a >> b;
			adj[a-1].push_back(b-1);
			degrees[b-1]++;
		}
		for(int i=0;i<n;i++){
			if(degrees[i]==0)p.push(i);
		}
		
		while(!p.empty()){
			r=p.top();
			p.pop();
			ans.push_back(r+1);
			for(int i=0;i<adj[r].size();i++){
				degrees[adj[r][i]]--;
				if(degrees[adj[r][i]]==0)p.push(adj[r][i]);
			}
		}
		if(ans.size()!=n)cout << "IMPOSSIBLE" << endl;
		else{
			for(int i=0;i<ans.size();i++){
				cout << ans[i] << endl;
			}
		}
		ans.clear();
	}
	return 0;
}
