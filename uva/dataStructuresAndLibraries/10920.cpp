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



int main() {FIN

	ll size, p, x, y;
	while(cin >> size >> p, size||p) {
	
		ll i = 1;
		while(p > i*i) i+=2; // find the ring containing p

		if(i == 1) {
	    		cout << "Line = " << (size/2)+1 << ", column = " << (size/2)+1 << ".\n";
	    		continue;
		}

		ll lb = (i-2)*(i-2), pad = (size-i)/2;
		if(p <= lb + i-1) {
	    		x = lb+i-p+pad;
	    		y = size-pad;
		} else if(lb + i-1 < p && p <= lb + 2*(i-1)) {
	    		x = pad+1;
	    		y = lb+(i-1)*2+1-p+pad;
		} else if(lb + 2*(i-1) < p && p <= lb + 3*(i-1)) {
	    		x = p-(lb+2*(i-1))+pad+1;
	    		y = pad+1;
		} else {
	    		x = size-pad;
	    		y = p-(lb+3*(i-1))+pad+1;
		}

		cout << "Line = " << y << ", column = " << x << ".\n";
    	}

	return 0;
}
