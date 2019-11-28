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

vll resta(vll& a, vll& b){
	vll c(20);
	fore(i,0,20){
		c[i]=a[i]-b[i];
	}
	return c;
}

bool isValid(vll& x){
	ll cont = 0;
	fore(i,0,20){
		if(x[i]&1) cont++;
	}
	if(cont>1) return 0;
	else return 1;
}

int main(){FIN
	ll n;
	string s;
	vll pos[20];
	vvll ss;
	
	cin >> n >> s;

	ss.assign(n+1,vll());
	
	vll cur(20,0),aux,aux2;
	ss[0] = cur;

	fore(i,0,n){
		pos[(s[i]-'a')].pb(i+1);
		cur[s[i]-'a']++;
		ss[i]=cur;
	}
	if(isValid(cur)){
		cout << n << "\n";
		return 0;
	}
	
	ll ans = 0;

	fore(i,0,20){
		if(SZ(pos[i]) && (n-pos[i][SZ(pos[i])-1]-1)<ans)continue;
		fore(j,0,SZ(pos[i])){
			aux = resta(cur,ss[pos[i][j]-1]);
			if(isValid(aux)) ans=max(ans,(n-pos[i][j]-1));
			else{
				fore(k,0,20){
					if(SZ(pos[k]) && (pos[k][SZ(pos[k])-1]-pos[i][j]) < ans) continue;
					fore(l,0,SZ(pos[k])){
						if(pos[k][l]<=pos[i][j])continue;
						aux2 = resta(cur,ss[pos[k][l]-1]);
						aux2 = resta(aux,aux2);
						if(isValid(aux2)) ans=max(ans,(pos[k][l]-pos[i][j]));
					}
				}
			}
			aux = resta(cur,ss[pos[i][j]-1]);
			aux = resta(cur, aux);
			if(isValid(aux)) ans=max(ans,(pos[i][j]));
		}
	}
	cout << ans << "\n";
	return 0;
}
