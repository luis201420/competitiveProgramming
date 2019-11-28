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
	ll d,s;
	double a,b,x,y;
	vector<double> c,e;

	cin >> t;
	fore(tt,1,t+1){
		cout << "Case #" << tt << ": ";
		cin >> d >> s;
		
		c.resize(s); e.resize(s);

		fore(i,0,s){
			cin >> c[i] >> e[i];
		}

		fore(i,0,d){
			cin >> a >> b;
			if(s==1){
				x = a/c[0];
				if(x>=0 && (e[0]*(1-x))>=b) cout << "Y";
				else cout << "N";
			}
			else{
				x = ((c[1]*(e[0]+e[1]-b))-(e[1]*a))/((c[1]*e[0])-(e[1]*c[0]));
				//DBG(x);
				if(x>=0){
					y = (a-(c[0]*x))/c[1];
					//DBG(y);
					if(y<=1)cout << "Y";
					else cout << "N";
				}
				else cout << "N";
			}
		}
		cout << "\n";


	}
	return 0;
}
