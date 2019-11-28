#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> g,used;
int r,c,m,n,w,x,y;
int contO,contE;

void dfs(int u,int v){
	if(used[u][v])return;
	used[u][v]=1;
	int cont = 0;
	vector<vector<bool>> marc;
	int aux = max(m,n);
	marc.assign(((aux+1)*2),vector<bool>(((aux+1)*2),1));
	if((u+m)<r && (v+n)<c && g[u+m][v+n] && marc[m+aux][n+aux]){
		cont++;
		dfs(u+m,v+n);
		marc[m+aux][n+aux]=0;

	}
	if((u-m)>=0 && (v-n)>=0 && g[u-m][v-n] && marc[(-m)+aux][(-n)+aux]){
		cont++;
		dfs(u-m,v-n);
		marc[(-m)+aux][(-n)+aux] = 0;
	}
	if((u+m)<r && (v-n)>=0 && g[u+m][v-n] && marc[(m)+aux][(-n)+aux]){
		cont++;
		dfs(u+m,v-n);
		marc[(m)+aux][(-n)+aux]=0;
	}
	if((u-m)>=0 && (v+n)<c && g[u-m][v+n] && marc[(-m)+aux][(n)+aux]){
		cont++;
		dfs(u-m,v+n);
		marc[(-m)+aux][(n)+aux]=0;
	}
	if((u+n)<r && (v+m)<c && g[u+n][v+m] && marc[(n)+aux][(m)+aux]){
		cont++;
		dfs(u+n,v+m);
		marc[(n)+aux][(m)+aux]=0;
	}
	if((u-n)>=0 && (v-m)>=0 && g[u-n][v-m] && marc[(-n)+aux][(-m)+aux]){
		cont++;
		dfs(u-n,v-m);
		marc[(-n)+aux][(-m)+aux]=0;
	}
	if((u+n)<r && (v-m)>=0 && g[u+n][v-m] && marc[(n)+aux][(-m)+aux]){
		cont++;
		dfs(u+n,v-m);
		marc[(n)+aux][(-m)+aux]=0;
	}
	if((u-n)>=0 && (v+m)<c && g[u-n][v+m] && marc[(-n)+aux][(m)+aux]){
		cont++;
		dfs(u-n,v+m);
		marc[(-n)+aux][(m)+aux]=0;
	}
	if(cont&1)contE++;
	else contO++;
}

int main(){
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> r >> c >> m >> n;
		g.assign(r,vector<bool>(c,1));
		cin >> w;
		while(w--){
			cin >> x >> y;
			g[x][y]=0;
		}
		contE = contO = 0;
		used.assign(r,vector<bool>(c,0));
		dfs(0,0);
		cout << "Case "<< i << ": " << contO << " " << contE <<endl;
	}
	return 0;
}
