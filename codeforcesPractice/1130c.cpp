#include <bits/stdc++.h>

using namespace std;

vector<string> f;
vector<vector<bool>> visited;
vector<pair<int,int>> res1,res2;

void dfs(int x,int y,bool v){
	if(v)res1.push_back({x,y});
	else res2.push_back({x,y});
	
	if((x+1)<f.size() && f[x+1][y]=='0'){
		if(!visited[x+1][y]){
			visited[x+1][y]=1;
			dfs(x+1,y,v);
		}
	}
	if((y+1)<f.size() && f[x][y+1]=='0'){
		if(!visited[x][y+1]){
			visited[x][y+1]=1;
			dfs(x,y+1,v);
		}
	}
	if((x-1)>=0 && f[x-1][y]=='0'){
		if(!visited[x-1][y]){
			visited[x-1][y]=1;
			dfs(x-1,y,v);
		}
	}
	if((y-1)>=0 && f[x][y-1]=='0'){
		if(!visited[x][y-1]){
			visited[x][y-1]=1;
			dfs(x,y-1,v);
		}
	}
}

int main(){
	string s;
	int n;
	cin >> n;
	int r1,c1,r2,c2;
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	r1--;r2--;c1--;c2--;
	for(int i=0;i<n;i++){
		cin >> s;
		f.push_back(s);
	}
	visited.assign(n,vector<bool>(n,0));
	dfs(r1,c1,1);
	if(visited[r2][c2])cout << 0 << endl;
	else{
		dfs(r2,c2,0);
		long long res = 1e9,aux,a,b;
		for(int i=0;i<res1.size();i++){
			for(int j=0;j<res2.size();j++){
				a = abs(res1[i].first-res2[j].first);
				b = abs(res1[i].second-res2[j].second);
				aux = (a*a)+(b*b);
				if(res>aux)res=aux;
			}
		}
		cout << res << endl;
	}
	return 0;
}
