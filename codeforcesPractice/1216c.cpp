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
	ll x1,y1,x2,y2;
	ll x3,y3,x4,y4;
	ll x5,y5,x6,y6;
	ll Xa,Ya,Xb,Yb;
	ll Xc,Xd,Yc,Yd;
	ll areaS,areaB;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;
	
	areaS = abs(x1-x2)*abs(y1-y2);

	Xa = max(x1,x3);
	Xb = min(x2,x4);
	Ya = max(y1,y3);
	Yb = min(y2,y4);

	
	areaB = 0;
	
	if(Xa<=Xb && Ya<=Yb)
		areaB += abs(Xa-Xb)*abs(Ya-Yb);	

	Xc = Xa;
	Yc = Ya;
	Xd = Xb;
	Yd = Yb;

	Xa = max(x1,x5);
	Xb = min(x2,x6);
	Ya = max(y1,y5);
	Yb = min(y2,y6);

	Xc = max(Xa,Xc);
	Xd = min(Xb,Xd);
	Yc = max(Ya,Yc);
	Yd = min(Yb,Yd);
	if(Xa<=Xb && Ya<=Yb)
		areaB += (abs(Xa-Xb)*abs(Ya-Yb));
	
	if(Xc<=Xd && Yc<=Yd)
		areaB -= (abs(Xc-Xd)*abs(Yc-Yd));

	if(areaB >= areaS) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}
