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

bool myComp(pair<string,ll> &a, pair<string,ll> &b){
	if(a.snd == b.snd){
		string da = a.fst;
		string db = b.fst;
		fore(i,0,SZ(da)) da[i]=tolower(da[i]);
		fore(i,0,SZ(db)) db[i]=tolower(db[i]);
		return lexicographical_compare(ALL(da),ALL(db));
	}
	else return a.snd < b.snd;
}

int main(){FIN
	ll n,row_count;
	string b1,b2,b3,b4;
	string name;
	ll minV, secV, msV;
	vector<pair<string,ll>> pilots;
	
	while(cin >> n){
		while(n--){
			cin >> name >> b1 >> minV >> b2 >> secV >> b3 >> msV >> b4;
			pilots.pb({name,msV+(1000*secV)+(60000*minV)});
		}
		sort(ALL(pilots),myComp);
		row_count = 1;
		fore(i,0,SZ(pilots)){
			if(i%2==0)cout << "Row " << row_count++ << "\n";
			cout << pilots[i].fst << "\n";
		}
		cout << "\n";
		pilots.clear();
	}
	return 0;
}
