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

vll cant;

void precal(){
	ll s=0;
	ll c = 1;
	ll acum = 1;
	bool v1,v2,v3,v4;
	v1 = v2 = v3 = v4 = 1;
	while(s <= 1000000010){
		cant.pb(s);
		s+=acum;
		acum+=c;
		if(acum>=10 && v1){acum++;c++;v1=0;}
		if(acum>=100 && v2){acum++;c++;v2=0;}
		if(acum>=1000 && v3){acum++;c++;v3=0;}
		if(acum>=10000 && v4){acum++;c++;v4=0;}
	}
}

int main(){FIN
	ll q,v,pos;
	string s;
	precal();
	cin >> q;
	vll::iterator it;
	while(q--){
		cin >> v;
		it = lower_bound(ALL(cant),v);

		if(it == cant.end()) pos = SZ(cant);
		else pos = it-cant.begin();
		
		v -= cant[pos-1];
		s="";
		fore(i,1,v+2){
			s+=to_string(i);
		}
		cout << s[v-1] << "\n";
		
	}
	return 0;
}
