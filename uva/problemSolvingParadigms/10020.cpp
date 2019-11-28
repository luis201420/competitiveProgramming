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

bool myComp(const pll &p1, const pll &p2){
	if(p1.fst == p2.fst)
		return p1.snd > p2.snd;
	return p1.fst < p2.fst;
}

int main(){FIN

	ll test,m,l,r,cur,p,maxP,maxV;
	vpll seg,ans;

	cin >> test;

	fore(tt,0,test){

		if(tt) cout << "\n";
		
		cin >> m;

		while(cin >> l >> r){
			if(l==0 && r==0)break;
			seg.pb({l,r});
		}

		sort(ALL(seg),myComp);
		//DBG(SZ(seg));	
		cur = 0;

		fore(i,0,SZ(seg)){
			//DBG(seg[i].fst); DBG(seg[i].snd);
			p = i;
			maxV = 1e-9;
			while(p<SZ(seg) && seg[p].fst <= cur){
				if(maxV < seg[p].snd){
					maxP=p;
					maxV=seg[p].snd;
				}
				p++;
			}
			if(p==i) break;
			ans.pb(seg[maxP]);
			cur = maxV;
			i=p-1;
			if(cur >=m)break;
		}
		if(cur>=m){
			cout << SZ(ans) << "\n";
			fore(i,0,SZ(ans)){
				cout << ans[i].fst << " " << ans[i].snd << "\n";
			}
		}
		else cout << "0\n";

		ans.clear();
		seg.clear();
	}
	return 0;
}
