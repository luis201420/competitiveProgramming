#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define SQR(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 11

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

ll x,y,a,b;
vll ns;
ll cal(ll lim){
	ll r = 0;
	ll c1 = 0, c2 = 0 , c3 = 0;
	fore(i,1,lim+1){
		if((i%a==0) && (i%b==0))c1++;
		else if(i%a==0) c2++;
		else if(i%b==0)c3++;
	}
	fore(i,0,c1) r+=(ns[i]*(x+y))/100;
	fore(i,0,c2) r+=(ns[c1+i]*x)/100;
	fore(i,0,c3) r+=(ns[c1+c2+i]*y)/100;
	return r;
}

int main(){FIN
	ll q,n,k,pi,pf,pm;

	cin >> q;
	while(q--){
		cin >> n;
		ns.resize(n);
		fore(i,0,n) cin >> ns[i];
		cin >> x >> a;
		cin >> y >> b;
		cin >> k;
		
		sort(ALL(ns),greater<ll>());
		
		if(y>x){
			swap(x,y);
			swap(a,b);
		}

		pi = 0, pf = n;
		while(pi <= pf){
			pm = (pi+pf)/2;
			if(cal(pm)>=k) pf = pm-1;
			else pi = pm+1;
		}
		if((pf+1) > n) cout << "-1\n";
		else cout << pf+1 << "\n";
	}
	return 0;
}
