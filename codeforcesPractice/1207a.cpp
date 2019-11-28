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

int main(){FIN
	ll t;
	ll b,p,f;
	ll h,c;
	ll cant,ans;

	cin >> t;
	while(t--){
		cin >> b >> p >> f;
		cin >> h >> c;
		
		cant = b/2;
		ans = 0;
		if(h<c){
			if(f>cant){
				ans += (cant*c);
				cant = 0;
			}
			else {
				ans += (f*c);
			       	cant-=f;	
			}
			if(p>cant){
				ans += (cant*h);
				cant = 0;
			}
			else{
				ans += (p*h);
				cant-=p;
			}
		}
		else{	
			if(p>cant){
				ans += (cant*h);
				cant = 0;
			}
			else{
				ans += (p*h);
				cant-=p;
			}
			if(f>cant){
				ans += (cant*c);
				cant = 0;
			}
			else {
				ans += (f*c);
			       	cant-=f;	
			}	
		}
		cout << ans << "\n";
		
	}
	return 0;
}
