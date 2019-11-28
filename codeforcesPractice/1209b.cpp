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
	ll n,t,ans,cont;
	string s;
	vpll ns;
	vll ss;

	cin >> n >> s;

	ss.resize(n);
	ns.assign(n,pll(0,0));
	
	fore(i,0,n){
		cin >> ns[i].fst >> ns[i].snd;
		ss[i] = ns[i].snd;
	}
	
	cont = 0;
	fore(i,0,n){
		if(s[i]=='1') cont++;
	}
	
	t = 0;
	ans = cont;
	while(t<10000){
		fore(i,0,n){
			if(ss[i]==t){
				if(s[i]=='1'){
					cont--;
					s[i] = '0';
				}
				else{
					cont++;
					s[i] = '1';
				}
				ss[i]+=ns[i].fst;
			}
		}
		ans = max(ans,cont);
		t++;
	}
	cout << ans << "\n";
	return 0;
}