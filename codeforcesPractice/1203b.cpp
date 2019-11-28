#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b,K) for(int i=a, ThxDem=b; i<ThxDem; i+=K)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) s.size()
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	
	ll q,n,r;
	vll ns,ls;
	
	cin >> q;
	ll cont,aux;
	bool ver;

	while(q--){
		cin >> n;
		ns.resize(4*n);
		fore(i,0,(4*n),1) cin >> ns[i];
		sort(ALL(ns));
		ver = 1;
		fore(i,1,SZ(ns),2){
			if(ns[i]!=ns[i-1])ver=0;
		}
		if(!ver){
			cout << "NO\n";
			continue;
		}
		r = ns[0]*ns[SZ(ns)-1];
		fore(i,2,SZ(ns)/2,2){
			if((ns[i]*ns[SZ(ns)-i-1])!=r)ver=0;
		}
		if(ver) cout << "YES\n";
		else cout << "NO\n";
		ls.clear();
	}
	return 0;
}
