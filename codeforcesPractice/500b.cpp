#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ns;
vector<string> board;
vector<bool> visited,used;

int res;

void dfs(int r){
	visited[r]=1;
	for(int i=0;i<n;i++){
		if(board[r][i]=='1' && !visited[i]){
			if(!used[i])res=(ns[res]>ns[i])?i:res;
			dfs(i);
		}
	}
	return;
}

int main(){
	int v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		ns.push_back(v);
	}
	string line;	
	for(int i=0;i<n;i++){
		cin >> line;
		board.push_back(line);
	}
	used.assign(n,0);
	for(int i=0;i<n;i++){
		res=i;
		visited.assign(n,0);
		dfs(i);
		used[i]=1;
		swap(ns[i],ns[res]);
	}
	for(int i=0;i<n;i++){
		if(i!=0) cout << " ";
		cout << ns[i] ;
	}
	cout << endl;
	return 0;
}
