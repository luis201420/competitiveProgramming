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
typedef vector<char> vchar;

map<ll,vchar> dig;
vector<string> dp;
ll mm;
ll n;

string minString(const string &s1, const string &s2){
	if(SZ(s1)<SZ(s2)) return s1;
	else if(SZ(s2)<SZ(s1)) return s2;
	else{
		fore(i,0,SZ(s1)){
			if(s1[i]!=s2[i]){
				if(s1[i]<s2[i])return s1;
				else return s2;
			}
		}
		return s1;
	}
}

string solve(ll s,ll d){

	if(s<0) return "";

	string & ans = dp[s];
	if(SZ(ans)) return ans;
	
	string aux,res;
	for(auto it=dig.rbegin();it!=dig.rend();it++){
		if((it->snd)[0]=='0' && d==0)
			aux = it->snd[1];
		else
			aux = it->snd[0];
		
		res = solve(s-it->fst,d+1);
		
		aux += res;
		if(SZ(ans))ans = minString(ans,aux);
		else ans = aux;
	}
	return ans;
}

int main(){FIN
	dig[2] = {'1'};
	dig[4] = {'4','7'};
	dig[5] = {'2','3','5'};
	dig[6] = {'0','6','9'};
	dig[7] = {'8'};
	ll t;
	cin >> t;
	while(t--){
		cin >> n;
		dp.assign(130,"");
		cout << solve(n,0) << "\n";
	}
	return 0;
}
