#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;

vll bit;
ll n;

ll sum(ll k){
	ll s = 0;
	while(k>=1){
		s+=bit[k];
		k-=(k&-k);
	}
	return s;
}

ll add(ll k, ll x){
	while(k<=n){
		bit[k]+= x;
		k+=(k&-k);
	}
}

int main(){FIN
	cin >> n;
	vll ns(n),ans(n);
	fore(i,0,n) cin >> ns[i];
	
	bit.assign(n+1,0);
	fore(i,1,n+1)add(i,i);
	ll x,l,r,m;
	for(int i=n-1;i>=0;i--){
		x=ns[i];
		l = 0;r=n;
		while(l<=r){
			m=(l+r)/2;
			if(sum(m)<=x)l=m+1;
			else r=m-1;
		}
		//DBG(m);
		ans[i]=r+1;
		add(r+1,-(r+1));
	}
	fore(i,0,n){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
