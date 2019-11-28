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

vstr ans;
string s,t;

void solve(ll posS, ll posT,string sol,stack<char> q){
	
	if(posT == SZ(t)){
		if(SZ(sol) == SZ(t)*2)
			ans.pb(sol);
		return ;
	}
	char aux;
	fore(i,posS,SZ(s)){
		if((!q.empty()) && q.top() == t[posT]){

			aux = q.top();
			q.pop();
			solve(i,posT+1,sol+"o",q);
			
			q.push(aux);
		}
		q.push(s[i]);
		sol+="i";
	}
	if((!q.empty()) && q.top() == t[posT]){

		aux = q.top();
		q.pop();
		solve(SZ(s),posT+1,sol+"o",q);
			
		q.push(aux);
	}	
}

int main(){FIN
	stack<char> q;

	while(cin >> s >> t){
		solve(0,0,"",q);
		sort(ALL(ans));
		cout << "[\n";
		fore(i,0,SZ(ans)){
			fore(j,0,SZ(ans[i])){
				if(j)cout << " ";
				cout << ans[i][j];
			}
			cout << "\n";
		}
		cout << "]\n";
		ans.clear();
	}
	return 0;
}
