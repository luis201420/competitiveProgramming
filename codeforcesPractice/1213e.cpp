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

bool valid1(string &s, string &t, string x){
	fore(i,0,SZ(x)-1){
		if(x.substr(i,2)==s || x.substr(i,2)==t)return 0;
	}
	return 1;
}

bool valid2(string &s, string &t,string x){
	if((x[0]==s[1] && x[SZ(x)-1]==s[0]) || (x[0]==t[1] && x[SZ(x)-1]==t[0]))return 0;
	return 1;
}

int main(){FIN

	ll n;
	cin >> n;
	string s,t,ans,aux;
	cin >> s >> t;
	string perm[6]={"abc","acb","bca","bac","cba","cab"};
	ans="";
	fore(i,0,6){
		if(valid1(s,t,perm[i])){
			if(valid2(s,t,perm[i])){
				ans = perm[i];
				break;
			}
			aux=string(n,perm[i][0])+string(n,perm[i][1])+string(n,perm[i][2]);
			if(valid1(s,t,aux)){
				ans=aux;
				break;
			}
		}
	}
	if(SZ(ans)){
		cout << "YES\n";
		if(SZ(ans)<(3*n)){
			fore(i,0,n){
				cout << ans;
			}
		}
		else cout << ans;
		cout << "\n";
	}
	else cout << "NO\n";
	return 0;
}
