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
#define EPS 1e-9
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

int p,q,r,s,t,u;

double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}


int main(){FIN
	double a,b,mid;
	cout << setprecision(4) << fixed;
	while(cin >> p >> q >> r >> s >> t >> u){
		
		if(f(0)*f(1) > 0){
			cout << "No solution\n";
			continue;
		}

		a = 0;
		b = 1;
		
		while( (a+EPS) < b){

			mid=(a+b)/2;
	
			if(f(mid)<=0) 
				b = mid;
			else 
				a = mid;
		}
		cout << (a+b)/2 << "\n";
	}
	return 0;
}
