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
	ll t,n,posC,aux,ini;
	vvll posV;
	string A,ans;
	bool ver;

	cin >> t;
	while(t--){
		cin >> n >> A;
		
		ans.assign(n,'-');
		posV.assign(10,vll());
		fore(i,0,n){
			posV[A[i]-'0'].pb(i);
		}
		posC = -1;
		ini = 10;

		fore(i,0,10){
			if(SZ(posV[i]) && i <= ini){

				fore(j,0,SZ(posV[i])){
					if(posV[i][j]<posC)continue;
					ans[posV[i][j]]='1';
				}
				posC = posV[i][SZ(posV[i])-1];

				fore(i,0,SZ(ans)){
					if(ans[i]=='-'){ini = A[i]-'0';break;}
				}
			}
		}
		aux = -1;
		ver = 1;

		fore(i,0,n){
			if(ans[i]=='-'){
				if(aux > (A[i]-'0')){ver=0;break;}
				aux = A[i]-'0';
				ans[i]='2';
			}
		}

		if(ver) cout << ans << "\n";
		else cout << "-\n";
	}
	return 0;
}
