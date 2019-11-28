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
	ll a,b;
	vll ans;
	cin >> a >> b;
	fore(i,1,sqrt(a)+1){
		if(a%i==0){
			if(i%b==0)ans.pb(i);
			if((a/i)!=i){
				if((a/i)%b==0)ans.pb(a/i);
			}
		}
	}
	sort(ALL(ans));
	fore(i,0,SZ(ans)){
		if(i)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
