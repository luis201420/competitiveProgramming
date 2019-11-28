#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define SZ(s) s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	ll t,n,s,ans;
	vll ns;

	cin >> t;
	
	while(t--){
		cin >> n;
		ns.resize(n);
		
		for(int i=0;i<n;i++)cin >> ns[i];
		
		ans = 1 + (n>1);
		s = 1;
		for(int i=1;i<(n-1);++i){
			if(s + ns[i] < ns[i+1]){
				s+=ns[i];
				ans++;
			}
		}	
		cout << ans << "\n";
	}
	return 0;
}
