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

bool ver(string a,string b){
	fore(i,0,SZ(a))
		if(a[i]=='1' && b[i]=='0') return 1;
	return 0;
}

int main(){FIN
	ll t,n,s,c,v,ans;
	vector<bitset<1001>> u;

	cin >> t;
	fore(tt,1,t+1){
		cin >> n >> s;
		
		u.assign(n,bitset<1001>());
		fore(i,0,n){
			cin >> c;
			while(c--){
				cin >> v;
				u[i].set(v);
			}
		}
		ans = 0;
		fore(i,0,n){
			fore(j,0,n){
				if(i!=j && ver(u[i].to_string(),u[j].to_string())){
					ans++;
				}
			}
		}
		cout << "Case #" << tt << ": "<< ans << "\n";
	}
	return 0;
}
