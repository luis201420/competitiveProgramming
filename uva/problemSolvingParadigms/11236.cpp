#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

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

int main(){FIN
	
	ll p,s,d;

	cout << setprecision(2) << fixed;

	for(ll a=1; (4*a) <=2000 ; a++){
		for(ll b=a ;(a+(3*b))<=2000;b++){
			for(ll c=b; (a+b+(2*c)) <= 2000;c++){
				
				p = (a*b*c);
				s = (a+b+c);

				if(p <= 1000000)continue;
				
				d = (1000000*s)/(p-1000000);

				if(d<c || (s+d)>2000)continue;

				if(fabs(((a+b+c+d)/100.0)-((a*b*c*d)/100000000.0)) < 1e-9){
					cout << a/100.0 << " ";
					cout << b/100.0 << " ";
					cout << c/100.0 << " ";
					cout << d/100.0 << "\n"; 
				}

			}
		}
	}
	return 0;
}
