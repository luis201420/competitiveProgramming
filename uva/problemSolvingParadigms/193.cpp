#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> graph;
vector<bool> used,res;
bool ver;
int maximo;

void s(int ini,int cont){
	if(ini==used.size()){

		ver = 1;
		for(int i=0;i<graph.size();i++){
			if(used[graph[i].first] && used[graph[i].second]){
				ver=0;
				break;
			}
		}
		
		if(ver && maximo<=cont){
			maximo=cont;
			res=used;
		}
		return;
	}
	used[ini]=1;
	s(ini+1,cont+1);
	used[ini]=0;
	s(ini+1,cont);
}

int main(){
	int m,a,b,x,y,cont;
	cin>>m;
	while(m--){
		cin >> a >> b;
		
		while(b--){
			cin >> x >> y;
			graph.push_back(make_pair(x-1,y-1));
		}

		maximo=0;
		used.assign(a,0);
		s(0,0);
		cont=0;
		cout << maximo << endl;
		
		for(int i=0;i<res.size();i++){
			if(res[i]){
				if(cont!=0)cout << " ";
				cout << i+1;
				cont++;
			}
		}
		cout << endl;
		graph.clear();
	}
	return 0;
}
