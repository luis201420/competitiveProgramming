#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<bool> vC,vR;
int n,ans;

void bt(int cont,int s){
	if(cont==n){
		if(s<ans)ans=s;
		return;
	}
	if(!vR[cont]){
		vR[cont]=1;
		for(int j=0;j<n;j++){
			if(!vC[j]){
				vC[j]=1;
				bt(cont+1,s+grid[cont][j]);
				vC[j]=0;
			}
		}
		vR[cont]=0;
	}
}

int main(){
	int t,v;
	cin  >> t;
	while(t--){
		cin >> n;
		grid.assign(n,vector<int>());
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> v;
				grid[i].push_back(v);
			}
		}

		vR.assign(n,0);
		vC.assign(n,0);
		ans = 100000;
		bt(0,0);
		cout << ans << endl;
	}
	return 0;
}
