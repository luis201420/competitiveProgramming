#include<bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin >> a;
	cin >> b;
	int n =  a.size();
	priority_queue<pair<int,pair<int,int>>> q;
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				q.push({dp[i][j],{i-1,j-1}});
			}
		}
	}
	vector<bool> usedA(n,0),usedB(n,0);
	pair<int,pair<int,int>> x;
	int ans=0;
	while(!q.empty()){
		x=q.top();
		q.pop();
		if(usedA[x.second.first] || usedB[x.second.second]) continue;
		ans++;
		for(int i=x.second.first;i>(x.second.first-x.first);i--)usedA[i]=1;
		for(int i=x.second.second;i>(x.second.second-x.first);i--)usedB[i]=1;
	}
	cout << (ans-1) << endl;
	return 0;
}
