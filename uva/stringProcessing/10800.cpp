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
typedef vector<string> vstr;

int main(){FIN
	
	ll t,minV,maxV;
	cin >> t;
	string s;
	vll pos,sizeA;
	vstr ans;

	fore(i,1,t+1){
		cin >> s;

		pos.assign(SZ(s),0);
		
		fore(j,0,SZ(s)){
			if(s[j]=='R'){
				if((j-1)>=0 && s[j-1]=='R')pos[j]=pos[j-1]+1;
				else if((j-1)>=0) pos[j]=pos[j-1];
			}
			if(s[j]=='F'){
				if((j-1)>=0 && (s[j-1]=='C'||s[j-1]=='F')) pos[j]=pos[j-1]-1;
				else if((j-1)>=0) pos[j]=pos[j-1];
			}
			if(s[j]=='C'){
				if((j-1)>=0 && s[j-1]=='R')pos[j]=pos[j-1]+1;
				else if((j-1)>=0) pos[j]=pos[j-1];
			}
		}
		minV = 1e9;maxV=0;
		fore(j,0,SZ(pos))minV = min(minV,pos[j]);
		//DBG(minV);
		fore(j,0,SZ(pos)) {pos[j]+=abs(minV); maxV = max(maxV,pos[j]);}
		
		ans.assign(maxV+1,"|"+string(SZ(s)+2,' '));
		ans.pb("+"+string(SZ(s)+2,'-'));
		sizeA.assign(maxV+1,0);
		sizeA.pb(SZ(s)+3);

		fore(j,0,SZ(s)){
			if(s[j]=='R'){ans[maxV-pos[j]][j+2]='/';sizeA[maxV-pos[j]]=j+3;}
			if(s[j]=='F') {ans[maxV-pos[j]][j+2]='\\';sizeA[maxV-pos[j]]=j+3;}
			if(s[j]=='C') {ans[maxV-pos[j]][j+2]='_';sizeA[maxV-pos[j]]=j+3;}
		}
		cout << "Case #" << i << ":\n";
		fore(j,0,SZ(ans))cout << ans[j].substr(0,sizeA[j]) << "\n";
		cout << "\n";
	}
	return 0;
}
