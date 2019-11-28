#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	string ord;
	cin >> n;
	string ans(10,'0');
	cin >> ord;
	int it;
	for(int i=0;i<n;i++){
		if(ord[i]=='L'){
			it=0;
			while(ans[it]=='1')it++;
			ans[it]='1';
		}
		else if(ord[i]=='R'){
			it=9;
			while(ans[it]=='1')it--;
			ans[it]='1';
		}
		else{
			ans[ord[i]-'0']='0';
		}
	}
	cout << ans << "\n";
	return 0;
}
