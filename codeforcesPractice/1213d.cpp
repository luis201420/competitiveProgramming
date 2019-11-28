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

int main(){FIN
	ll ans;
	ll n,k,mm=0;
	cin >> n >> k;
	map<ll,ll> cont;
	
	vll ns(n);
	fore(i,0,n){
		cin >> ns[i];
		cont[ns[i]]++;
		mm = max(mm,ns[i]);
	}

	ans = INF;
	ll aux,ac,v,r,mov,rr;
	
	fore(i,1,200501){
		v = i;
		aux = cont[v];
		
		r=1;
		rr=2;
		mov=0;
		while(aux < k){
			v*=2;
			ac=0;
			fore(j,0,rr){
				if((v+j) > mm)break;
				ac += cont[v+j];
			}
			if(v>mm)break;
			//DBG(v);
			ac = min(k-aux,ac);
			aux += ac;
			mov += (r*ac);
			//if(mov>ans)break;
			r++;
			rr*=2;
		}
		if(aux>=k){
			//DBG(i);
			ans = min(mov,ans);
		}
	}
	cout << ans << "\n";
	return 0;
}
