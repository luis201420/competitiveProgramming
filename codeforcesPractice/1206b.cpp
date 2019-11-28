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
	ll n,v,ans,contN,contZ;
	cin >> n;
	contN=contZ=ans=0;
	fore(i,0,n){
		cin >> v;
		if(v<0) contN++;
		if(v==0){contZ++;}
		else ans += abs(v)-1;
	}
	if(contN&1 && contZ>0) {ans++;contZ--;}
	else if(contN&1 && contZ==0) ans+=2;
	ans+=contZ;
	cout << ans << "\n";
	return 0;
}
