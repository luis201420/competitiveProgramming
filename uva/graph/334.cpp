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
				dist[i][j] = (dist[i][j] | (dist[i][k] & dist[k][j]));
			}
		}
	}
}

int main(){FIN
	ll x,s,ans,test=1;
	string name1,name2,ansC;
	map<string,ll> ids;
	vector<string> names;
	
	while(cin >> x){
		if(x==0)break;

		dist.assign(400,vbool(400,0));
		
		while(x--){
			cin >> s;
			fore(i,0,s){
				if(i==0){
					cin >> name1;
					if(ids[name1]==0){
						names.pb(name1);
						ids[name1]=SZ(names);
					}
				}
				else{
					cin >> name2;
					if(ids[name2]==0){
						names.pb(name2);
						ids[name2]=SZ(names);
					}
					dist[ids[name1]-1][ids[name2]-1]=1;
					name1=name2;
				}
			}
		}
		n = SZ(names);
		cin >> s;
		while(s--){
			cin >> name1 >> name2;
			dist[ids[name1]-1][ids[name2]-1]=1;
		}

		fw();

		ans = 0;
		ansC = ":\n";

		fore(i,0,n){
			fore(j,i+1,n){
				if(!dist[i][j] && !dist[j][i]){
					ans++;
					if(ans<=2){
						ansC+="("+names[i]+","+names[j]+")";
						ansC+=" ";
					}
				}
			}
		}
		cout << "Case " << test++ << ", ";
		if(ans==0){cout << "no";ansC=".";}
		else cout << ans;
	        cout<< " concurrent events" << ansC << "\n";
		ids.clear();
		names.clear();
	}
	return 0;
}
