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
	ll t,n,p1,p2;
	vll ns;
	bool ver;
	cin >> t;
	while(t--){
		cin >> n;
		ns.resize(n);
		for(int i=0;i<n;i++){
			cin >> ns[i];
			if(ns[i]==1)p1=i;
			if(ns[i]==n)p2=i;
		}
		ver = 1;
		for(int i=0;i<n;i++){
			if(ns[(p1+i)%n]!=(i+1))ver=0;
		}
		if(ver){
			cout << "YES\n";
			continue;
		}
		ver = 1;
		for(int i=0;i<n;i++){
			if(ns[(p1+(2*n)-i)%n]!=(i+1))ver=0;
		}
		if(ver) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
