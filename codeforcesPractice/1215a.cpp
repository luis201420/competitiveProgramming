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
	ll a1,a2,k1,k2,n;
	ll ans1,ans2;
	
	cin >> a1 >> a2;
	cin >> k1 >> k2;
	cin >> n;

	ll v = ((k1-1)*a1)+(a2*(k2-1));

	if(v >= n){
		ans1 = 0;
	}
	else{
		ans1 = n-v;
	}

	ans2 = 0;

	if(k2 < k1){
		swap(k1,k2);
		swap(a1,a2);
	}
	v = n / k1;
	if(v > a1) v = a1;
	ans2 += v;
	n-=(v*k1);
	v = n / k2;
	if(v > a2) v = a2;
	ans2 += v;
	n-=(v*k2);

	cout << ans1 << " " << ans2 << "\n";
	return 0;
}
