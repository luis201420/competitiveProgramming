#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) s.size()
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	ll n,v;
	cin >> n;
	vll ns(n);
	fore(i,0,n)cin >> ns[i];
	sort(ALL(ns));
	map<ll,int> cont;
	fore(i,0,n){
		v=ns[i];
		if(v>1 && cont[v-1]<=0)cont[v-1]++;
		else if(cont[v]<=0)cont[v]++;
		else cont[v+1]++;
	}
	ll ans = 0;
	for(auto it:cont){
		if(it.second>0) ans++;
	}
	cout << ans << "\n";
	return 0;
}
