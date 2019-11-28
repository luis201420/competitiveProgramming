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
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vbool> vvbool;

vvbool dist;
ll n;

void fw(){
	fore(k,0,n){
		fore(i,0,n){
			fore(j,0,n){
				dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
			}
		}
	}
}

void print(){
	fore(i,0,n){
		fore(j,0,n){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){FIN

	map<string,ll> ids;
	vector<string> ws;
	ll cont,j,u;
	string s,aux;
	vll ans;
	set<string> ans2;

	while(cin >> n && n){
		
		getline(cin,s);
	
		cont=1;
		dist.assign(n,vbool(n,0));
		fore(i,0,n)dist[i][i]=1;

		fore(i,0,n){
			getline(cin,s);
			aux="";
			j = 0;
			while(j<SZ(s) && s[j]!=' '){aux+=s[j];j++;}
			if(ids[aux]==0){ids[aux]=cont++;ws.pb(aux);}
			u=ids[aux]-1;
			aux="";
			j++;
			while(j<SZ(s)){
				if(s[j]==' '){
					if(ids[aux]==0){ids[aux]=cont++;ws.pb(aux);}
					dist[u][ids[aux]-1]=1;
					aux="";
				}
				else{aux+=s[j];}
				j++;
			}
			if(SZ(aux)){
				if(ids[aux]==0){ids[aux]=cont++;ws.pb(aux);}
				dist[u][ids[aux]-1] = 1;
				aux="";
			}
		}

		fw();

		ll c;

		fore(i,0,n){
			c = 0;
			fore(j,0,n){
				if(i!=j && dist[i][j] && dist[j][i]){ans.pb(j);c++;}
			}
			if(c){
				ans.pb(i);
			}
		}

		fore(i,0,SZ(ans)){
			fore(j,0,n){
				if(dist[ans[i]][j])ans2.insert(ws[j]);
			}
			ans2.insert(ws[ans[i]]);
		}

		j = 0;
		
		cout << SZ(ans2) << "\n";
		for(string us: ans2){
			if(j)cout << " ";
			cout << us;
			j++;	
		}
		cout << "\n";

		ans2.clear();
		ans.clear();
		ws.clear();
		ids.clear();
	}
	return 0;
}
