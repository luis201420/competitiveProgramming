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
	ll C,S,ad,x,set=0;
	double p,imb;
	vll ss;
	cout << setprecision(5) << fixed;
	while(cin >> C >> S){
		ss.resize(S);
		p=0;
		fore(i,0,S){
			cin >> ss[i];
			p+=ss[i];
		}
		p/=double(C);
		ad = 2*C-S;
		fore(i,0,ad) ss.pb(0);
		sort(ALL(ss));
		cout << "Set #" << set+1 << "\n";
		set++;
		imb=0;
		fore(i,0,C){
			cout << " "<< i << ":";
			if(ss[i]>0) cout <<" "<< ss[i];
			if(ss[SZ(ss)-i-1]>0)cout <<" "<< ss[SZ(ss)-i-1];
		       	cout<< "\n";
			x= ss[i]+ss[SZ(ss)-i-1];
			imb += fabs(p-x);
		}
		cout << "IMBALANCE = " << imb << "\n\n";
	}
	return 0;
}
