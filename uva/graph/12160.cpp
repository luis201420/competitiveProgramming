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
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<string> vstr;

vvll adj;
vll btn,dist;
ll ans;

void bfs(ll iv, ll ov){
	dist[iv]=0;
	queue<ll> q;
	q.push(iv);
	ll u,v;
	while(!q.empty()){
		u = q.front(); q.pop();
		fore(i,0,SZ(btn)){
			v=(u+btn[i])%10000;
			if(dist[v] == 1e9){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){FIN
	ll L, U, R,test=1;
	while(cin >> L >> U >>R){
		
		if((L+U+R)==0)break;
		
		btn.resize(R);
		
		fore(i,0,R) cin >> btn[i];
		
		cout << "Case " << test++ << ": ";
		
		dist.assign(10000,1e9);
		bfs(L,U);
		
		if(dist[U]<1e9) cout << dist[U] ;
		else cout << "Permanently Locked";
		cout << "\n";
	}
	return 0;
}
