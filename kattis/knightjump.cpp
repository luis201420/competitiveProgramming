#include <bits/stdc++.h>

using namespace std;

vector<string> g;
vector<vector<bool>> used;
vector<vector<int>> dist;
int n;

void dijkstra(int r, int c){
	priority_queue<pair<int,pair<int,int>>> q;
	q.push({0,{r,c}});
	dist[r][c]=0;
	int x,y,d;
	
	while(!q.empty()){
		d=-(q.top().first);
		x=q.top().second.first;
		y=q.top().second.second;
		q.pop();
		used[x][y]=1;
		if((x+2)<n && (y+1)<n && !used[x+2][y+1] && g[x+2][y+1]=='.' && dist[x+2][y+1]>(d+1)){
			dist[x+2][y+1] = d+1;
			q.push({-(d+1),{x+2,y+1}});
		}
		if((x+2)<n && (y-1)>=0 && !used[x+2][y-1] && g[x+2][y-1]=='.' && dist[x+2][y-1]>(d+1)){
			dist[x+2][y-1]=d+1;
			q.push({-(d+1),{x+2,y-1}});
		}
		if((x-2)>=0 && (y+1)<n && !used[x-2][y+1] && g[x-2][y+1]=='.' && dist[x-2][y+1]>(d+1)){
			dist[x-2][y+1]=d+1;
			q.push({-(d+1),{x-2,y+1}});
		}
		if((x-2)>=0 && (y-1)>=0 && !used[x-2][y-1] && g[x-2][y-1]=='.' && dist[x-2][y-1]>(d+1)){
			dist[x-2][y-1]=d+1;
			q.push({-(d+1),{x-2,y-1}});
		}
		if((x+1)<n && (y+2)<n && !used[x+1][y+2] && g[x+1][y+2]=='.' && dist[x+1][y+2]>(d+1)){
			dist[x+1][y+2]=d+1;
			q.push({-(d+1),{x+1,y+2}});
		}
		if((x+1)<n && (y-2)>=0 && !used[x+1][y-2] && g[x+1][y-2]=='.' && dist[x+1][y-2]>(d+1)){
			dist[x+1][y-2]=d+1;
			q.push({-(d+1),{x+1,y-2}});
		}
		if((x-1)>=0 && (y+2)<n && !used[x-1][y+2] && g[x-1][y+2]=='.' && dist[x-1][y+2]>(d+1)){
			dist[x-1][y+2]=d+1;
			q.push({-(d+1),{x-1,y+2}});
		}
		if((x-1)>=0 && (y-2)>=0 && !used[x-1][y-2] && g[x-1][y-2]=='.' && dist[x-1][y-2]>(d+1)){
			dist[x-1][y-2]=d+1;
			q.push({-(d+1),{x-1,y-2}});
		}
	}
}

int main(){
	int r,c;
	cin >> n;
	g.resize(n);
	dist.assign(n,vector<int>(n,1e9));
	used.assign(n,vector<bool>(n,0));
	for(int i=0;i<n;i++){
		cin >> g[i];
		for(int j=0;j<g[i].size();j++){
			if(g[i][j]=='K'){
				r=i;c=j;
			}
		}
	}
	dijkstra(r,c);
	if(dist[0][0]<1e9){
		cout << dist[0][0] << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}
