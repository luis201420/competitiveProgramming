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
	ll q,n,r;
	string s[2];
	bool ver;
	cin >> q;

	while(q--){
		cin >> n;
		cin >> s[0] >> s[1];
		r = 0;
		ver = 1;
		fore(i,0,n){
			if('3'<=s[r][i]){
				if(s[(r+1)%2][i]<'3') ver = 0;
				else r=(r+1)%2;
			}
		}
		if(ver && r) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}
