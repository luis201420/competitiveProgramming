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

int main(){FIN
	ll n;
	vll ans;
	cin >> n;
	if(n&1){
		cout << "YES\n";
		ans.resize(n<<1);
		fore(i,0,n){
			if(i&1){
				ans[i]   = (i+1)<<1;
				ans[i+n] = (i<<1)+1;
			}
			else{
				ans[i]   = (i<<1)+1;
				ans[i+n] = (i+1)<<1;
			}
		}
		fore(i,0,SZ(ans)){
			if(i)cout << " ";
			cout << ans[i];
		}
		cout << "\n";
	}
	else cout << "NO\n";
	return 0;
}
