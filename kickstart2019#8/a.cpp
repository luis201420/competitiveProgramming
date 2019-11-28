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

const ll N = 100010;
vll bit;

ll sum(ll k){
	ll s=0;
	while(k>=1){
		s += bit[k];
		k -= k&-k;
	}
	return s;
}

void add(ll k, ll x){
	while(k<=N){
		bit[k] += x;
		k += k&-k;
	}
}

ll bs(){
	ll a = 0, b = N-1,k;
	while(a<=b){
		k = (a+b)/2;
		if(sum(k)>=(N-k))b=k-1;
		else a=k+1;
	}
	ll sa = sum(a),sb=sum(b);
	if(sa>=(N-a) && sb>=(N-b)){
		return max(N-a,N-b);
	}
	else if(sa>=(N-a)) return (N-a);
	else return (N-b);
}

int main(){FIN
	
	ll t,n,v;

	cin >> t;

	fore(tt,0,t){
		cin >> n;
		cout << "Case #" << tt+1 << ":";
		bit.assign(N,0);
		while(n--){
			cin >> v;
			add(N-v,1ll);
			cout << " " << bs();
		}
		cout << "\n";
	}
	return 0;
}
