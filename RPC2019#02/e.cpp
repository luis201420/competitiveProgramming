#include <bits/stdc++.h>

using namespace std;

vector<string> allB;
vector<vector<bool>> visited;
vector<vector<int>> dp;
int r,c;

int res = 1e9;

int dfs(int a,int b){


	//if(z>=res) return;

	if(dp[a][b]<1e9)return dp[a][b];

	if(a==(r-1) || b==(c-1) || (a==0) || (b==0)){
		//res=min(res,z);
		return dp[a][b]=0;
	}
	
	int v1=1e9;
	if(a+1<r && !visited[a+1][b] && allB[a+1][b]!='#'){
		visited[a+1][b]=1;
		if(allB[a+1][b]=='c'){
			v1=min(v1,1+dfs(a+1,b));
		}
		else{
		       	v1=min(v1,dfs(a+1,b));
		}
		visited[a+1][b]=0;
	}
	if(b+1<c && !visited[a][b+1] && allB[a][b+1]!='#'){
		visited[a][b+1]=1;
		if(allB[a][b+1]=='c'){
			v1=min(v1,1+dfs(a,b+1));
		}
		else{
		       v1=min(v1,dfs(a,b+1));
		}
		visited[a][b+1]=0;
	}
	if(a-1>=0 && !visited[a-1][b] && allB[a-1][b]!='#'){
		visited[a-1][b]=1;
		if(allB[a-1][b]=='c'){
			v1=min(v1,1+dfs(a-1,b));
		}
		else{
			v1=min(v1,dfs(a-1,b));
		}
		visited[a-1][b]=0;
	}
	if(b-1>=0 && !visited[a][b-1] && allB[a][b-1]!='#'){
		visited[a][b-1]=1;
		if(allB[a][b-1]=='c'){
			v1=min(v1,1+dfs(a,b-1));
		}
		else{
		       v1=min(v1,dfs(a,b-1));
		}
		visited[a][b-1]=0;
	}	
	//if(allB[a][b]=='c')v1++;
	

	dp[a][b]=/*min(dp[a][b],*/(v1);
	return dp[a][b];
}

int main(){
	string line;
	cin >> r >> c;
	visited.assign(r,vector<bool>(c,0));
	dp.assign(r,vector<int>(c,1e9));
	for(int i=0;i<r;i++){
		cin >> line;
		allB.push_back(line);
	}
	int x,y;
	cin >> x >> y;
	visited[x-1][y-1]=1;
	/*dfs(x-1,y-1,0);
	cerr << res + 1 << endl;*/
	dfs(x-1,y-1);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cerr << dp[i][j] << "\t";
		}
		cerr << endl;
	}
	cout  << dp[x-1][y-1]+1 << endl;
	return 0;
}
