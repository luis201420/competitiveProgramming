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

struct Point{
	ll x,y,z;
};

ll n,k;

bool ver(const Point &p1, const Point &p2){
	//return (3*SQR(2*k)) > (SQR(p1.x-p2.x)+SQR(p1.y-p2.y)+SQR(p1.z-p2.z));
	return ((2*k)>abs(p1.x-p2.x) && (2*k)>abs(p1.y-p2.y) && (2*k)>abs(p1.z-p2.z));
}

int main(){FIN
	ll t;
	ll a,b,c,X,Y,Z,sum;
	vector<Point> vp;

	cin >> t;
	while(t--){
		cin >> n >> k;
		fore(i,0,n){
			cin >> a >> b >> c;
			vp.pb({a,b,c});
		}
		sum = 0;
		fore(i,0,n){
			fore(j,i+1,n){
				if(ver(vp[i],vp[j])){
					X = (2*k) - abs(vp[i].x-vp[j].x);
					Y = (2*k) - (2*abs(vp[i].y-vp[j].y));
					Z = (2*k) - (2*abs(vp[i].z-vp[j].z));
					sum += X*Y*Z;
				}
			}
		}
		cout << (n*8*k*k*k)-sum << "\n";
		vp.clear();
	}
	return 0;
}
