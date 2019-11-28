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
	ll t,n,m,K,ansA,ansS,s,auxA;
	vvll A;

	cin >> t;
	fore(tt,1,t+1){
		cin >> n >> m >> K;
		A.assign(n,vll(m,0));

		fore(i,0,n){
			fore(j,0,m){
				cin >> A[i][j];
				if(i > 0) A[i][j] += A[i-1][j];
				if(j > 0) A[i][j] += A[i][j-1];
				if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
			}
		}

		ansS = ansA = 0;

		fore(i,0,n){
			fore(j,0,m){
				fore(k,i,n){
					fore(l,j,m){
						s = A[k][l];
						if(i > 0) s -= A[i-1][l];
						if(j > 0) s -= A[k][j-1];
						if(i > 0 && j > 0) s += A[i-1][j-1];
						if(s<=K){
							auxA = (k-i+1)*(l-j+1);
							if((auxA == ansA && s < ansS)||(auxA > ansA)){
								ansA=auxA;
								ansS=s;
							}
						}
					}
				}
			}
		}
		cout << "Case #" << tt << ": " << ansA << " " << ansS << "\n";
	}
	return 0;
}
