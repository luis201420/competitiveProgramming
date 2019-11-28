#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int n;
vector<vector<int>> adj ,capacity;

int bfs(int s, int t, vector<int>& parent) {
    parent.assign(n,-1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int main(){
	int s,t,c,cont=1;
	int u,v,b,flow,new_flow;
	vector<int> parent;
	while(cin >> n){
		if(n==0)break;
		adj.assign(n,vector<int>());
		capacity.assign(n,vector<int>(n,0));
		cin >> s >> t >> c;
		while(c--){
			cin >> u >> v >> b;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
			capacity[u-1][v-1]+=b;
			capacity[v-1][u-1]+=b;
		}
		flow = 0;
		s--;t--;
		while(new_flow = bfs(s,t,parent)){
			flow+=new_flow;
			int cur = t;
			while(cur != s){
				int prev = parent[cur];
				capacity[prev][cur]-=new_flow;
				capacity[cur][prev]+=new_flow;
				cur = prev;
			}
		}
		cout << "Network " << cont << endl;
		cout <<"The bandwidth is "<< flow << "." << endl << endl;
		cont++;
	}
	return 0;
}
