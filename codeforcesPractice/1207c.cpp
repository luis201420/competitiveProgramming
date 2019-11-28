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
	ll t,n,a,b;
	string s;
	ll ans;
	bool one;

	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		cin >> s;
		
		one=0;
		ans=0;
		
		ll i = 0,cont=0;;
		while(i<n && s[i]=='0'){cont++;i++;}
		
		ans+= (cont-1)*a;
		ans+= (cont*b);

		if(i<n && s[i]=='1')ans+=(2*a);
		else ans+=(a+b);

		while(i<n){
			cont = 0;
			while(i<n && s[i]=='1'){cont++;i++;}
			ans+=(cont*a);
			ans+=(cont+1)*(2*b);
			cont = 0;
			while(i<n && s[i]=='0'){cont++;i++;}
			if(i<n && s[i]=='1'){
				if((cont*b)>(a+b)){
					ans+=(((cont+2)*a) + ((cont-1)*(b)));
				}
				else{
					ans+=(((cont+1)*a) + ((cont-1)*b*2));
				}
			}
			else{
				if((cont*b) > a) ans+= ((cont+1)*a + (cont*b));
				else ans+= (cont*b*2)+(cont*a);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
