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
	ll q,c,ans,ps;
	string s;
	cin >> q;
	while(q--){
		cin >> s;
		//DBG(SZ(s));
		fore(j,1,SZ(s)){
			c=0;
			while(c<SZ(s) && (j+c)<SZ(s) && s[c]==s[j+c])c++;
			if((j+c)>=SZ(s) && c>=j){
				ans=c;
				ps=j;
				break;
			}
		}
		//DBG(ans);
		//DBG(ps);
		//s=s.substr(0,ps);
		fore(i,0,8) cout << s[(ans+i)%ps];
		cout << "...\n";
	}
	return 0;
}
