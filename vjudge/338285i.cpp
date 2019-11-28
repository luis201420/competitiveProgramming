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

string P,T;
vll b;
ll n,m,ans;

void kmpPreprocess(){
	ll i=0,j=-1;
	b[0]=-1;
	while(i<m){
		while(j>=0 && P[i]!=P[j]) j=b[j];
		i++; j++;
		b[i]=j;
	}
}

void kmpSearch(){
	ll i=0, j=0;
	while(i<n){
		while(j>=0 && T[i]!=P[j])j=b[j];
		i++;j++;
		if(i<n && j==m) j=b[j];
	}
	ans=j;
}

int main(){FIN
	while(cin >> P >> T){
		m = SZ(P);
		n = SZ(T);
		b.resize(m+1);
		kmpPreprocess();
		ans=-1;
		kmpSearch();
		if(ans)cout << P.substr(0,ans) <<" ";
		cout << ans << "\n"; 
	}
	return 0;
}
