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
ll m;

bool verificate(ll C){
	
	ll contCur = 1;
	ll cant = C;

	fore(i,0,SZ(ns)){
		if(ns[i]>C)return 0;

		if(ns[i]>cant){
			if(contCur == m) return 0;
			contCur++;
			cant = C;
		}
		cant -= ns[i];
	}
	return 1;
}

int main(){FIN
	ll n,ans,a,b,mid;
	
	while(cin >> n >> m){
		
		ns.resize(n);

		fore(i,0,n) cin >> ns[i];
		
		a = 1;b=1000000000;
		
		ans = 0;
		
		while(a<=b){

			mid=(a+b)/2;
			
			if(verificate(mid)){
				ans = mid;
				b = mid-1;
			}
			else a = mid+1;
		}
		cout << ans << "\n";
		
	}
	return 0;
}
