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
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mpll;
typedef pair<int,int> pii;
typedef vector<string> vstr;

vll primes;
mpll divN;

void sieve(){
	ll limit = 1000000;
	vector<bool> used(limit+1,1);
	for(ll p=2;(p*p)<limit;p++){
		if(used[p]){
			divN[p]=p;
			for(ll j=p*2;j<limit;j+=p){
				used[j]=0;
				divN[j]=p;
			}
		}
	}
	fore(p,2,limit)
		if(used[p]) primes.pb(p);
}

bool ver(ll x){
	mpll cont;
	while(x>1){
		//DBG(divN[x]);
		cont[divN[x]]++;
		x/=divN[x];
	}
	ll s1,s2;
	s1 = s2 = 1;
	for(auto it:cont){
		if(it.fst&1) s1*=(cont[it.fst]+1);
		s2*=(cont[it.fst]+1);
	}
	ll e = s1*cont[2];
	ll o =  s2-e;
	return (abs(e-o)<=2);
}

int main(){FIN
	sieve();
	ll t,L,R,ans,ss,test=1;
	
	cin >> t;
	while(t--){
		cin >> L >> R;
		fore(i,0,SZ(primes)){
			ll toLim = floor(L/primes[i])*primes[i];
			if(toLim < L) toLim += primes[i];

			for(ll j=toLim;j<=R;j+=primes[i]){
				divN[j]=primes[i];
			}
		}
		ss = (R-L);
		cout << "Case #"<<test++ << ": ";
		ans = 0;
		fore(i,L,R+1){
			if(ver(i)){
				//DBG(i);
				ans++;
			}
		}
		cout << ans<< "\n";
	}
	return 0;
}
