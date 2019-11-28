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
	ll n,v,c0,c1,s0,s1,aux;
	ll q0,q1;
	string s;

	cin >> n;
	cin >> s;
	c0 = c1 = 0;
	s0 = s1 = 0;
	fore(i,0,n){
		if(i<(n/2)){
			if(s[i]=='?')c0++;
			else s0 += s[i]-'0';
		}
		else{
			if(s[i]=='?')c1++;
			else s1 += s[i]-'0';
		}
	}
	s0 += c0/2*9;
	s1 += c1/2*9;
	if(s0 == s1) cout << "Bicarp\n";
	else cout << "Monocarp\n";
	return 0;
}
