#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long x,y;
	cin >> n >> x >> y;
	
	vector<long long> dp;

	dp.assign(n,0);
	dp[0]=x;

	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+x;
		if(i&1) dp[i]= min(dp[i],dp[i/2]+y);
		else dp[i]=min(dp[i],dp[i/2]+y+x);
	}
	cout << dp[n-1] << endl;
	return 0;
}
