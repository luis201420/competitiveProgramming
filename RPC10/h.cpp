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
	ll n,q,qs,pos,v,ans;
	vll A,S;
	cin >> n >> q;
	
	A.resize(n);

	fore(i,0,n)cin >> A[i];

	sort(ALL(A));
	fore(i,1,n)S.pb(A[i]+A[i-1]);

	vll::iterator it;
	fore(i,0,q){
		cin >> qs;
		it = lower_bound(ALL(S),qs);
		if(it == S.end()) pos = SZ(A)-1;
		else{
			pos = it-S.begin();
			pos++;
			if((*it)>qs) pos--;
		}
		ll j = pos + 1 ;
		ans =(j*(j-1))/2;;
		while(j < SZ(A) && A[j]<qs){
			v = qs - A[j];
			pos = upper_bound(ALL(A),v)-A.begin();
			ans += pos;
			j++;
		}
		cout << ans << "\n";
	}
	return 0;
}
