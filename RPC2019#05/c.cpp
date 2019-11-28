#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,ant,v;
	cin >> n >> m;
	vector<int> ns(n);
	priority_queue<int> w;
	priority_queue<pair<int,pair<int,int>>> dist;
	ant=-1;
	vector<vector<bool>> visited(n,vector<bool>(n,0));
	for(int i=0;i<n;i++){
		cin >> ns[i];
		if(ant!=-1){
			dist.push({-(ns[i]-ant),{i-1,i}});
			visited[i-1][i]=1;
		}
		ant=ns[i];
	}
	for(int i=0;i<m;i++){
		cin >> v;
		w.push(-v);
	}
	int cW,cD,xi,xj;
	bool ver=1;
	while(!w.empty()){
		cW=-w.top();
		if(dist.empty()){
			ver=0;
			break;
		}
		cD=-dist.top().first;
		//cerr << cW << " " << cD << endl;
		if(cD<=cW){
			xi=(dist.top().second).first;
			xj=(dist.top().second).second;
			w.pop();
			dist.pop();
			if(xj+1 < n && (xj+1)!=xi && !visited[xi][xj+1]){
				dist.push({-(ns[xj+1]-ns[xi]),{xi,xj+1}});
				visited[xi][xj+1]=1;
			}
			if(xi+1 < n && (xi+1)!=xj && !visited[xi+1][xj]){
				dist.push({-(ns[xj]-ns[xi+1]),{xi+1,xj}});
				visited[xi+1][xj]=1;
			}
		}
		else{
			ver=0;
			break;
		}
	}
	if(ver)cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
