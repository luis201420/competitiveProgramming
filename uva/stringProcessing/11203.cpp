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

int main(){FIN
	ll q,p;
	vll cont;
	string s;
	cin >> q;
	while(q--){
		cin >> s;
		cont = {0,0,0};
		p=0;
		fore(i,0,SZ(s)){
			if(s[i]=='M' || s[i]=='E')p++;
			if(p<3 && s[i]=='?') cont[p]++;
		}
		if(p>=3 || p < 2 || (2+cont[0]+cont[1]+cont[2])!=SZ(s) || cont[0]==0 || cont[1]==0 || cont[2]==0){
			cout << "no-theorem\n";
			continue;
		}
		if(cont[2]-cont[1]+1-cont[0]==1) cout << "theorem\n";
		else cout << "no-theorem\n";
	}
	return 0;
}
