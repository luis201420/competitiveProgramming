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

vll ns;

bool simulate(ll K){
	ll ant = 0,v;
	fore(i,0,SZ(ns)){
		v=ns[i]-ant;
		ant = ns[i];
		if(K>=v){
			if(K==v)K--;
		}
		else return 0;
	}
	return 1;
}

int main(){FIN

	ll t;
	ll n,a,b,m,ans;

	cin >> t;
	fore(i,1,t+1){
		cout << "Case "<< i << ": ";
		cin >> n;
		ns.resize(n);
		fore(i,0,n)cin >> ns[i];
		a = 1; b = 10000000;
		ans = 1e9;
		while(a<=b){
			m=(a+b)/2;
			if(simulate(m)){
				ans = min(ans,m);
				b = m-1;
			}
			else a = m+1;
		}
		cout << ans << "\n";
	}
	return 0;
}
