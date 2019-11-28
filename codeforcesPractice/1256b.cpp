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
	ll t,n,v,k,c,aux;
	vll ns;
	vbool used;

	cin >> t;
	while(t--){
		cin >> n;
		ns.resize(n);
		used.assign(n,0);

		fore(i,0,n)cin >> ns[i];
		
		fore(i,1,n+1){
			fore(j,0,n){
				if(ns[j]==i){
					for(int k=j-1;k>=0;k--){
						if(!used[k] && ns[k]>ns[k+1]){
							used[k]=1;
							swap(ns[k],ns[k+1]);
						}
					}
					break;
				}
			}
		}
		fore(i,0,n){
			if(i) cout << " ";
			cout << ns[i];
		}
		cout << "\n";
	}
	return 0;
}
