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
	string S,Q;
	ll q;

	cin >> S;
	cin >> q;

	vvll pos(60,vll());

	fore(i,0,SZ(S)){
		pos[S[i]-'A'].pb(i);
	}

	ll id,currentPos,l,r;
	vll::iterator it;
	bool ver;
	
	while(q--){
		cin >> Q;
		currentPos = 0;
		l=-1;
		ver=1;
		fore(i,0,SZ(Q)){
			id = Q[i]-'A';
			it = lower_bound(ALL(pos[id]),currentPos);
			if(it == pos[id].end()){
				cout << "Not matched\n";
				ver=0;
				break;
			}
			if(l == -1) l = *it;
			r = *it;
			currentPos=r+1;
		}
		if(ver)cout << "Matched " << l << " " << r << "\n";
	}
	return 0;
}
