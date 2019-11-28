#include <bits/stdc++.h>

#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ALL(s) s.begin(),s.end()
#define SZ(s) s.size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	ll n,d,r,ans;
	vll m,e;
	while(cin >> n >> d >> r){
		if((n+d+r)==0)break;
		m.resize(n);
		e.resize(n);
		for(int i=0;i<n;i++)cin >> m[i];
		for(int i=0;i<n;i++)cin >> e[i];
		sort(ALL(m));
		sort(ALL(e));
		reverse(ALL(e));
		ans=0;
		for(int i=0;i<n;i++){
			if((m[i]+e[i])>d)
				ans+=((m[i]+e[i])-d);
		}
		cout << ans*r << "\n";
	}
	return 0;
}

