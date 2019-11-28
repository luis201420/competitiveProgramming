#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> match;

bool aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
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
	vector<string> board;
	vector<vector<int>> m;
	string line;
	int n,id1,id2,res;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> line;
			board.push_back(line);
		}
		id2=0;
		m.assign(n,vector<int>(n,-1));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[j][i]=='X'){
					if(j+1<n && j-1>=0 && board[j-1][i]=='.')id2++;
				}
				else m[j][i]=id2;
			}
			id2++;
		}
		id1=0;
		adj.push_back(vector<int>());
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(m[i][j]==-1){
					if(j+1<n && j-1>=0 && m[i][j-1]!=-1){
						id1++;
						adj.push_back(vector<int>());
					}
				}
				else adj[id1].push_back(m[i][j]);
			}
			adj.push_back(vector<int>());
			id1++;
		}
		res=0;
		match.assign(id2,-1);
		for(int i=0;i<id1;i++){
			visited.assign(id1,0);
			res+=aug(i);
		}
		cout << res << endl;
		board.clear();
		adj.clear();
	}
	return 0;
}
