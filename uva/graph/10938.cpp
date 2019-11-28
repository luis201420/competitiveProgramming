#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int,int>> A;
vector<int> pos;

void dfs(int r,int l){
	visited[r]=1;
	if(pos[r]==-1)pos[r]=A.size();
	A.push_back({l,r});
	for(int i=0;i<adj[r].size();i++){
		if(!visited[adj[r][i]]){
			dfs(adj[r][i],l+1);
			A.push_back({l,r});
		}
	}
}

/*  Sparse Table */

vector<vector<int>> T;

void create(){
	for(int i=0;i<A.size();i++){
		T[0][i]=i;
	}
	int s;
	for(int i=1;(1<<i)<=A.size();i++){
		s=1<<(i-1);
		for(int j=0;(j+(s<<1))<=A.size();j++){
			if(A[T[i-1][j]].first < A[T[i-1][j+s]].first)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j+s];
		}
	}
}

int rmq(int a,int b){
	int s = (b-a)+1;
	int k = log2(s);
	if(A[T[k][a]].first < A[T[k][(b-(1<<k))+1]].first)
		return A[T[k][a]].second;
	else
		return A[T[k][(b-(1<<k))+1]].second;
}

/*****************/

int main(){
	int n,a,b,q,dist,lca,nmin,aux;
	while(cin >> n){
		if(n==0) break;
		
		adj.assign(n,vector<int>());
		visited.assign(n,0);
		pos.assign(n,-1);
		for(int i=1;i<n;i++){
			cin >> a >> b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		dfs(0,0);
		T.assign(log2(A.size())+1, vector<int>(A.size(),-1));
		create();
		cin >> q;
		while(q--){
			cin >> a >> b;
			a--;b--;
			lca = rmq(min(pos[a],pos[b]),max(pos[a],pos[b]));
			dist = A[pos[a]].first+A[pos[b]].first-(2*A[pos[lca]].first);
			
			//cerr << lca <<" "<< dist << endl;
			if(A[pos[a]].first<A[pos[b]].first)nmin=b;
			else nmin=a;
			for(int j=0;j<(dist/2);j++){
				for(int i=0;i<adj[nmin].size();i++){
					if(A[pos[adj[nmin][i]]].first < A[pos[nmin]].first){
						nmin=adj[nmin][i];
						break;
					}
				}
			}
			if(dist&1){
				for(int i=0;i<adj[nmin].size();i++){
                                        if(A[pos[adj[nmin][i]]].first < A[pos[nmin]].first){
                                                aux=adj[nmin][i];
                                                break;
                                        }
                                }
				cout << "The fleas jump forever between "<<min(nmin+1,aux+1) << " and " << max(nmin+1,aux+1) << ".\n";
			}
			else{
				cout << "The fleas meet at "<< nmin+1 <<".\n";
			}
		}
		A.clear();
	}
	return 0;
}
