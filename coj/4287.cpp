#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,t;
	scanf("%d %d %d",&n,&m,&t);
	//cin >> n >> m >> t;
	set<pair<int,int>> p,aux;
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		//cin >> a >> b;
		p.insert({a,b});
	}
	map<pair<int,int>,int> g;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		//cin >> a >> b;
		g[{a,b}]=1;
	}
	for(int i=0;i<t;i++){
		for(auto it:p){
			a=it.first;
			b=it.second;
			g[{a,b}]=1;
			if((a-1)>=0 && g[{a-1,b}]==0){
				g[{a-1,b}]=1;
				aux.insert({a-1,b});
			}
			if((b-1)>=0 && g[{a,b-1}]==0){
				g[{a,b-1}]=1;
				aux.insert({a,b-1});
			}
			aux.insert({a+1,b});
			aux.insert({a,b+1});
		}
		p=aux;
	}
	printf("%d\n",int(p.size()));
	return 0;
}
