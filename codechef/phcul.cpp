#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

#define SQR(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 11

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

struct node{
	string ss;
	ll group, id;
};

bool operator <(const node &a, const node &b){
	return a.group > b.group;
}

double caldist(const pdd & a, const pdd &b){
	double dx = fabs(a.fst-b.fst);
	double dy = fabs(a.snd-b.snd);

	return sqrt(SQR(dx)+SQR(dy));
}

int main(){FIN

	cout << setprecision(11) << fixed;

	ll t,n,m,k;
	double x,y,X,Y;
	double ans;

	vpdd ps[3];
	vbool vis[3];
	vector<double> dist[3];
	
	cin >> t;
	while(t--){
		cin >> x >> y;

		cin >> n >> m >> k;
		
		vis[0].assign(n,0);
		vis[1].assign(m,0);
		vis[2].assign(k,0);

		dist[0].assign(n,1e15);
		dist[1].assign(m,1e15);
		dist[2].assign(k,1e15);

		while(n--){
			cin >> X >> Y;
			ps[0].pb({X,Y});
		}
		while(m--){
			cin >> X >> Y;
			ps[1].pb({X,Y});
		}
		while(k--){
			cin >> X >> Y;
			ps[2].pb({X,Y});
		}
		
		priority_queue<pair<double,node>> p;  // <distance,<,idNode>
		p.push({0,{"000",-1,0}});
		pair<double,node> u;
		string mask;
		pdd pc;
		double Dist,ant;

		ans = 1e15;

		while(!p.empty()){
			u = p.top(); p.pop();
			mask = u.snd.ss;

			//DBG(mask);

//			if(vis[u.snd.group][u.snd.id]) continue;
//			vis[u.snd.group][u.snd.id] = 1;

			if(u.snd.group == -1){
				pc = {x,y};
			}
			else{
				pc = {ps[u.snd.group][u.snd.id].fst,ps[u.snd.group][u.snd.id].snd};
			}

			ant = u.fst;

			//DBG(SZ(p));
			//DBG(u.snd.group);// DBG(u.snd.id);

			if(mask[0]=='0'){
				mask[0] = '1';
				fore(i,0,SZ(ps[0])){
					Dist = caldist(pc,ps[0][i]);
					//if(dist[0][i] > (ant+Dist)){
						//dist[0][i] = min(dist[0][i],ant+Dist);
						//p.push({-dist[0][i],{mask,0,i}});
					//}
					p.push({ant+Dist,{mask,0,i}});
				}
				mask[0]='0';
			}
			if(mask[1]=='0'){
				mask[1]='1';
				fore(i,0,SZ(ps[1])){
					Dist = caldist(pc,ps[1][i]);
					//if(dist[1][i] > (ant+Dist)){
					//	dist[1][i] = min(dist[1][i],ant+Dist);	
					//	p.push({-dist[1][i],{mask,1,i}});
					//}
					p.push({ant+Dist,{mask,1,i}});
				}
				mask[1]='0';
			}
			if(mask[0]=='1' && mask[1]=='1' && mask[2]=='0'){
				mask[2]='1';
				fore(i,0,SZ(ps[2])){
					Dist = caldist(pc,ps[2][i]);
					//if(dist[2][i] > (ant+Dist)){
					//	dist[2][i] = min(dist[2][i],ant+Dist);
					//	p.push({-dist[2][i],{mask,2,i}});
					//}
					//	p.push({ant+Dist,{mask,2,i}});
						ans = min(ans,ant+Dist);
					//}
				}
				mask[2]='0';
				break;
			}
		}
		ps[0].clear();
		ps[1].clear();
		ps[2].clear();
		cout << ans << "\n";
	}
	return 0;
}
