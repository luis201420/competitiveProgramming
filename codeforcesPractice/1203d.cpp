#include <bits/stdc++.h>

#define fst first
#define snd second
#define foru(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define ford(i,a,b) for(int i=a, ThxDem=b; i>=ThxDem; --i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){FIN
	string s,t;
	cin >> s >> t;

	vll rp(SZ(t));
	ll p1;

	ford(i,SZ(t)-1,0){
		p1 = SZ(s)-1;
		if((i+1)<SZ(t)) p1 = rp[i+1]-1;
		while(t[i]!=s[p1])p1--;
		rp[i]=p1;
	}

	ll ans = 0,p2;
	p1 = 0;

	foru(i,0,SZ(s)){
		p2 = SZ(s)-1;
		if(p1 < SZ(t)) p2 = rp[p1]-1;
		ans = max(ans, p2-i+1);
		if(p1 < SZ(t) && t[p1]==s[i])p1++;
	}

	cout << ans << "\n";

	return 0;
}
