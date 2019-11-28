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
typedef map<ll,ll> mll;

bool ver(mll &cont){
	for(auto it:cont)
		if(it.snd>1)return 0;
	return 1;
}

int main(){FIN
	
	ll n;
	vll ns;
	mll cont;
	ll lx,ly;

	cin >> n;
	ns.resize(n);

	lx=-1;
	fore(i,0,n){
		cin >> ns[i];
		cont[ns[i]]++;
		if(cont[ns[i]]>=2){
			if(lx == -1)lx=i;
			ly=i;
		}
	}
	ll x,y;
	x=y=0;
	while(!ver(cont)){
		if(x<n)cont[ns[x]]--;
		x++;
	}
	while(ver(cont) &&  y <= x){
		if(y<n)cont[ns[y]]++;
		y++;
	}
	//DBG(lx);
	//DBG(ly);
	cout << min((x-y)+1,(ly-lx)+1) << "\n";
	return 0;
}
