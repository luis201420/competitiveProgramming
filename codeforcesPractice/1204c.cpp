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
	ll n,m,v;
	string s;

	cin >> n;
	vector<vll> dist(n,vll(n,1e9));
	fore(i,0,n){
		cin >> s;
		fore(j,0,n){
			if(s[j]=='1') dist[i][j]=1;
		}
	}

	fore(k,0,n){
		fore(i,0,n){
			fore(j,0,n){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	cin >> m;
	vll p;
	fore(i,0,m){
		cin >> v;
		p.pb(--v);
	}
	
	vll::iterator i,j,k;	
	
	i = p.begin();
	
	while(SZ(p) > 2 && i!=p.end()){
		k=i;k++;
		if(k==p.end())break;
		j=k;j++;
		if(j==p.end())break;
		if(dist[*i][*j] == dist[*i][*k]+dist[*k][*j] && *i!=*j) p.erase(k);
		else i++;
	}

	cout << SZ(p) << "\n";

	for(int x:p){
		cout << x+1 << " ";
	}
	cout << "\n";

	return 0;
}
