#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SZ(s) s.size()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<int, pii> pip;

vector<ll> bit, ys;

ll sum(int k){
	ll s=0;
	while(k>=1){
		s+=bit[k];
		k-=(k&-k);
	}
	return s;
}

void add(int k, ll x){
	while(k<=SZ(ys)){
		bit[k]+=x;
		k+=(k&-k);
	}
}

bool myComp(pip &a, pip &b){
	return a.snd.fst > b.snd.fst;
}

int main(){
	FIN
	ll n;
	
	cin >> n;
	vector<pip> ns(n,{0,{0,0}});
	
	for(int i=0;i<n;i++){
		ns[i].first=i;
		cin >> ns[i].snd.fst >> ns[i].snd.snd;
		ys.pb(ns[i].snd.snd);
	}

	sort(ALL(ys));
	ys.erase(unique(ALL(ys)), ys.end());

	bit.assign(SZ(ys)+1,0);
	
	sort(ALL(ns),myComp);
	
	int id;

	vector<ll> ans (n);

	for(int i=0;i<n;i++){
		//cerr << ns[i].fst << " " << ns[i].snd << "\n";
		id = lower_bound(ALL(ys),ns[i].snd.snd) - ys.begin();
		ans[ns[i].fst] = sum(id+1);
		add(id+1,+1);
	}

	for(int v:ans) cout << v << "\n";
	return 0;
}
