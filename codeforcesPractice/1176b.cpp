#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,v;
	cin >> t;
	vector<int> res;
	int ans;
	while(t--){
		cin >> n;
		res.assign(3,0);
		ans=0;
		for(int i=0;i<n;i++){
			cin >> v;
			if(v%3==0)ans++;
			else if(res[v%3]>0){
				res[v%3]--;
				ans++;
			}
			else{
				res[3-(v%3)]++;
			}
		}
		
		cout << ans+(res[1]/3)+(res[2]/3) << endl;
	}
	return 0;
}
