#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> match;

int aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<graph[ini].size();i++){
		int r=graph[ini][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}


int main(){
	
	int white,black;
	int scenarios;
	int h,w,res;
	string line;
	vector<string> lines;
	vector<vector<int>> cont;
	
	cin >> scenarios;
	
	while(scenarios--){
		
		cin >> h >> w;
		while(h--){
			cin >> line;
			lines.push_back(line);
		}

		white = black = 0;
		cont.assign(lines.size(),vector<int>(w,-1));

		for(int i=0;i<lines.size();i++){
			for(int j=0;j<lines[i].size();j++){
				if(lines[i][j]=='*'){
					if((i+j)%2==0){
						cont[i][j]=white;
						white++;
					}
					else {
						cont[i][j]=black;
						black++;
					}
				}
			}
		}
		
		graph.assign(white,vector<int>());

		for(int i=0;i<lines.size();i++){
			for(int j=i%2;j<lines[i].size();j+=2){
				if(lines[i][j]=='*'){
					if(i-1>=0 && lines[i-1][j]=='*')graph[cont[i][j]].push_back(cont[i-1][j]);
					if(j-1>=0 && lines[i][j-1]=='*')graph[cont[i][j]].push_back(cont[i][j-1]);
					if(i+1<lines.size() && lines[i+1][j]=='*')graph[cont[i][j]].push_back(cont[i+1][j]);
					if(j+1<lines[i].size() && lines[i][j+1]=='*')graph[cont[i][j]].push_back(cont[i][j+1]);
				}
			}
		}

		match.assign(black,-1);
		res=0;
	
		for(int i=0;i<graph.size();i++){
			visited.assign(white,0);
			res+=aug(i);
		}
		
		cout << (black+white)-res << endl;
		
		lines.clear();
	}
	return 0;
}
