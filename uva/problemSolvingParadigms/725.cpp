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

vbool num;

bool verificate(ll a){
	if(a<10000){
		if(num[0])return 0;
		num[0]=1;
	}
	while(a>0){
		if(num[a%10])return 0;
		num[a%10]=1;
		a/=10;
	}
	return 1;
}

int main(){FIN
	ll n,y,test=0;
	bool ans;
	while(cin >> n && n){
		if(test)cout << "\n";
		test++;
		ans = 0;
		fore(x,1234,98766){
			y = n*x;
			num.assign(10,0);
			if(verificate(y) && verificate(x)){
				ans = 1;
				
				if(y < 10000) cout << 0;
				cout << y << " / " ;
				if(x < 10000) cout << 0;
				cout << x << " = " << n << "\n";
			}
		}
		if(!ans)cout << "There are no solutions for " << n << ".\n";
	}
	return 0;
}
