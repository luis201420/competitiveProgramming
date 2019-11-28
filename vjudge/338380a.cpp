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

bool myComp(const string &s1, const string &s2){
	return SZ(s1)<SZ(s2);
}

int main(){FIN
	ll t,n;
	vector<string> ns;
	string s;
	map<string,int> cont;
	bool ver;

	cin >> t;
	while(t--){
		cin >> n;
		ns.resize(n);
		fore(i,0,n) cin >> ns[i];
		sort(ALL(ns),myComp);
		ver=1;
		fore(i,0,n){
			s="";
			fore(j,0,SZ(ns[i])){
				s+=ns[i][j];
				if(cont[s]){
					ver=0;
					break;
				}
			}
			cont[ns[i]]=1;
			if(!ver)break;
		}
		if(ver) cout << "YES\n";
		else cout << "NO\n";
		cont.clear();
	}
	return 0;
}
