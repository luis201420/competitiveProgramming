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

string P;
ll m;
vll b;

void kmpPreprocess(){
	ll i=0,j=-1;
	b[0]=-1;
	while(i<m){
		while(j>=0 && P[i]!=P[j]) j=b[j];
		i++; j++;
		b[i]=j;
	}
}

int main(){FIN

	ll x;
	vll ans;

	while(cin >> P){
		m = SZ(P);
		b.resize(m+1);
		kmpPreprocess();
		fore(i,0,m+1)DBG(b[i]);
		x=SZ(P);
		while(x>0){
			ans.pb(x);
			x=b[x];
		}
		sort(ALL(ans));
		fore(i,0,SZ(ans)){
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << "\n";
		ans.clear();
	}
	return 0;
}
