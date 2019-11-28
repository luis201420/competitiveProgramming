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

bool isSimilar(string a, string b){
	
	if(abs(SZ(a)-SZ(b))>1) return 0;
	
	ll cont=0,j=0;

	if(SZ(a)>SZ(b))swap(a,b);

	fore(i,0,SZ(b)){
		while(i<SZ(b) && b[i]!=a[j])i++;
		if(i<SZ(b)){
			cont++;
			j++;
			if(j>=SZ(a)) break;
		}
	}

	if(cont==SZ(a)) return 1;
	else{
		if(SZ(a)!=SZ(b)) return 0;
		vll pos;
		fore(i,0,min(SZ(a),SZ(b))){
			if(a[i]!=b[i])pos.pb(i);
		}
		if(SZ(pos)==1) return 1;
		if(SZ(pos)==2 && (pos[1]-pos[0])==1 && (a[pos[0]]==b[pos[1]]) && (a[pos[1]]==b[pos[0]])) return 1;
		return 0;
	}
}

int main(){FIN
	ll n,q;
	string s,ans;
	vector<string> dic;
	cin >> n;
	while(n--){
		cin >> s;
		dic.pb(s);
	}
	cin >> q;
	bool ver;
	while(q--){
		cin >> s;
		ver = 0;
		ans = "";
		fore(i,0,SZ(dic)){
			if(dic[i]==s){ver=1; break;}
			if(isSimilar(s,dic[i]) && SZ(ans)==0){ans = dic[i];}
		}
		if(ver) cout << s << " is correct\n";
		else{
			if(SZ(ans))cout << s << " is a misspelling of " << ans << "\n";
			else cout << s << " is unknown\n";
		}
	}
	return 0;
}
