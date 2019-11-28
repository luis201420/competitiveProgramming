#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

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

string valid[10]={"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY",
		  "YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"};


vstr ns;
ll n;
bool ans;

bool verif(int x, int y){
	fore(i,0,7){
		if(ns[x][i]!=valid[y][i]){
			if(ns[x][i]=='Y')return 0;
			else{
				fore(j,x,SZ(ns)){
					if(ns[j][i]=='Y')return 0;
				}
			}
		}
	}
	return 1;
}

void bt(int r,int lim){
	if(r==n){
		ans = 1;
		return;
	}
	if(r){
		if((lim-1)>=0 && verif(r,lim-1)){
			//DBG(lim-1);
			bt(r+1,lim-1);
		}
		return;
	}
	for(int i=(lim-1);i>=0;i--){
		if(verif(r,i)){
			//DBG(i);
			bt(r+1,i);
		}
		if(ans)return;
	}
	return;
}

int main(){FIN

	while(cin >> n && n){

		ns.resize(n);
		fore(i,0,n)cin >> ns[i];
		
		ans = 0;
		
		bt(0,10);
		
		if(ans) cout << "MATCH\n";
		else cout << "MISMATCH\n";
	}
	return 0;
}
