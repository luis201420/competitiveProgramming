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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

int main(){FIN
	ll s, d;
	ll mS,mD,cM,ans,aux;
	while(cin >> s >> d){
		mS = (5 * d)/(s+d);

		if(mS < 1){
			cout << "Deficit\n";
			continue;
		}

		mD = 5 - mS;
		ans = 0;
		cM = 0;
		while(cM < 12){
			aux = min(mS,12-cM);
			ans += (s*aux);
			cM += aux;

			aux = min(mD,12-cM);
			ans -= (d*aux);
			cM += aux;
		}

		if(ans < 0) cout << "Deficit\n";
		else cout << ans << "\n";
	}
	return 0;
}
