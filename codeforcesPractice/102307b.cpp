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

ll b[5010];
ll ans;

void kmpPreprocess(string &P){
	ll m = SZ(P);
	ll i = 0, j = -1;
	b[0] = -1;
	while(i < m){
		while(j>=0 && P[i]!=P[j]) j = b[j];
		i++;j++;
		b[i]=j;
	}
}

void kmpSearch(string &T, string &P){
	ll n = SZ(T), m = SZ(P);
	ll i = 0, j = 0;
	while(i<n){
		while(j >= 0 && T[i]!=P[j]) j = b[j];
		i++;j++;
		ans = j;
		if(j == m) j=b[j];
	}
}

int main(){FIN
	string s,a;
	
	cin >> s;
	a = s;
	reverse(ALL(s));

	kmpPreprocess(s);
	
	kmpSearch(a,s);
	cout << a+s.substr(ans) << "\n";
	return 0;
}
