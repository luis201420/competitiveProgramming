#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<pair<long long,long long>>> adj;
vector<pair<long long,long long>> h;
vector<long long> pos,dist;
 
/** Sparse Table  **/
/*******************/
vector<vector<long long>> T;
 
void create(){
        for(long long i=0;i<h.size();i++){
                T[0][i]=i;
        }
        long long s;
        for(long long i=1;(1<<i)<=h.size();i++){
                s=1<<(i-1);
                for(long long j=0;(j+(s<<1))<=h.size();j++){
                        if(h[T[i-1][j]].first < h[T[i-1][j+s]].first)
                                T[i][j]=T[i-1][j];
                        else
                                T[i][j]=T[i-1][j+s];
                }
        }
}
 
long long rmq(int a,int b){
        long long s = (b-a)+1;
        long long k = log2(s);
        if(h[T[k][a]].first < h[T[k][(b-(1<<k)) +1]].first)
                return h[T[k][a]].second;
        else
                return h[T[k][(b-(1<<k)) +1]].second;
}
/*******************/
 
void dfs(long long r,long long l,long long p){
        if(pos[r]==-1)pos[r]=h.size();
        h.push_back({l,r});
        for(long long i=0;i<adj[r].size();i++){
		if(p!=adj[r][i].first){
			dist[adj[r][i].first]=dist[r]+adj[r][i].second;
       	       		dfs(adj[r][i].first,l+1,r);
               		h.push_back({l,r});
		}
        }
 
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long n,t,a,b,w,lca,aux;
	string op;
	cin >> t;
	for(long long c=0;c<t;c++){
		if(c!=0)cout << endl;
		cin >> n;
		adj.assign(n,vector<pair<long long,long long>>());
		pos.assign(n,-1);
		dist.assign(n,0);
		for(int i=1;i<n;i++){
			cin >> a >> b >> w;
			adj[a-1].push_back({b-1,w});
			adj[b-1].push_back({a-1,w});
		}
		dfs(0,0,-1);
		T.assign(log2(h.size())+1,vector<long long>(h.size(),-1));
		create();
		while(cin >> op){
			if(op == "DONE") break;
			cin >> a >> b;
			a--;b--;
			lca = rmq(min(pos[a],pos[b]),max(pos[a],pos[b]));
			if(op == "DIST"){
				cout << (dist[a]+dist[b])-(2*dist[lca]) << endl;
			}
			if(op == "KTH"){
				cin >> w;
				w--;
				aux = h[pos[a]].first - h[pos[lca]].first;
				if(w<=aux){
					while(w--){
						for(pair<long long,long long> u:adj[a]){
							if(h[pos[u.first]].first<h[pos[a]].first){
								a=u.first;break;
							}
						}
					}
					cout << a+1 << endl;
				}else{
					w=(w-aux)-(h[pos[b]].first-h[pos[lca]].first);
					w=abs(w);
					while(w--){
						for(pair<long long,long long> u:adj[b]){
							if(h[pos[u.first]].first<h[pos[b]].first){
								b=u.first;break;
							}
						}
					}
					cout << b+1 << endl;
				}
			}
		}
		h.clear();
	}
	return 0;
}
