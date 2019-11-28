#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> match;
vector<bool> visited;

int aug(int ini){
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
	
	vector<int> aux;
	string line;
	vector<string> board;
	vector<vector<int>> ids;
	int c,r,white,black,cont;

	while(cin >> r >> c){
		ids.assign(r,vector<int>(c,-1));
		for(int i=0;i<r;i++){
			cin >> line;
			board.push_back(line);
		}
		white=black=0;
		for(int i=0;i<r;i++){
			for(int j=!(i&1);j<c;j+=2){
				if(board[i][j]!='X'){
					ids[i][j]=white;
					white++;
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=(i&1);j<c;j+=2){
				if(board[i][j]!='X'){
					if((i+1) < r && ids[i+1][j]!=-1) aux.push_back(ids[i+1][j]);
					if((j+1) < c && ids[i][j+1]!=-1) aux.push_back(ids[i][j+1]);
					if((i-1) >= 0 && ids[i-1][j]!=-1)aux.push_back(ids[i-1][j]);
					if((j-1) >= 0 && ids[i][j-1]!=-1)aux.push_back(ids[i][j-1]);
					black++;
					adj.push_back(aux);
					aux.clear();
				}
			}
		}
		match.assign(white,-1);
		cont=0;
		
		for(int i=0;i<black;i++){
			visited.assign(black,0);
			cont+=aug(i);
		}
	
		if((cont*2) == (black+white)) cout << 2;
		else cout << 1;
		cout << endl;
		board.clear();
		adj.clear();
	}
	return 0;
}
