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

pll searchMinMax(vll &x){
	ll pmin,pmax,vmin,vmax;
	vmin=1e9;
	vmax=-1e9;
	pmin = pmax = -1;
	fore(i,0,SZ(x)){
		if(x[i]<vmin){
			vmin=x[i];
			pmin=i;
		}
		if(x[i]>=vmax){
			vmax=x[i];
			pmax=i;
		}
	}
	return make_pair(pmin,pmax);
}

int main(){FIN
	ll n,cad,cws,ansV,ansH,ans;
	string s;
	vll vws,vad;
	pll pos,lad,lws;

	cin >> n;

	while(n--){
		cin >> s;

		cad = cws = 0;
		lad = {0,0};
		lws = {0,0};

		vws.pb(0);vad.pb(0);

		fore(i,0,SZ(s)){
			if(s[i]=='A'){
				cad+=1;
				vad.pb(cad);
			}
			if(s[i]=='D'){
				cad+=-1;
				vad.pb(cad);
			}
			if(s[i]=='W'){
				cws+=1;
				vws.pb(cws);
			}
			if(s[i]=='S'){
				cws+=-1;
				vws.pb(cws);
			}
			lad = {min(lad.fst,cad),max(lad.snd,cad)};
			lws = {min(lws.fst,cws),max(lws.snd,cws)};
		}

		ansV = (lad.snd-lad.fst+1); ansH=(lws.snd-lws.fst+1);
		DBG(ansV);DBG(ansH);
		ans = ansV*ansH;

		pos = searchMinMax(vws);
		if(pos.fst > pos.snd) ans = min(ans, (max(ansH-1,2ll))*(ansV));

		pos = searchMinMax(vad);
		if(pos.fst > pos.snd) ans = min(ans, (ansH)*(max(ansV-1,2ll)));
		
		fore(i,0,SZ(vws)) vws[i]*=-1;
		fore(i,0,SZ(vad)) vad[i]*=-1;

		pos = searchMinMax(vws);
		//DBG(pos.fst);DBG(pos.snd);
		if(pos.fst > pos.snd) ans = min(ans, (max(2ll,ansH-1))*(ansV));

		pos = searchMinMax(vad);
		if(pos.fst > pos.snd) ans = min(ans, (ansH)*(max(2ll,ansV-1)));

		cout << max(ans,2ll) << "\n";
		vws.clear();
		vad.clear();
	}	
	return 0;
}
