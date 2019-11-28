#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph3d,graph2d;
vector<bool> visited;

bool dfs(int ini,bool d,int l){	
	//cerr << ini << endl;
	if(visited[ini]){
		//cerr << ini << "()" << l << endl;
		if(l!=-1 && l!=ini)return true;
		else return false;
	}
	visited[ini]=1;
	set<int> aux;
	if(d)aux = graph3d[ini];
	else aux = graph2d[ini];
	bool cont = 0;
	set<int>::iterator it;
	for(it=aux.begin();it!=aux.end();it++){
		//cerr << ini << " : " << *it << ";" << l << endl;
		if(*it!=l) cont|=dfs(*it,d,ini);
	}
	return cont;
}

int main(){
	map<vector<int>,int> points3d,points2d;	
	int k,x,y,z,id1,id2,id3,id4,i,j;
	while(cin >> k){
		i=1;j=1;
		graph3d.assign((2*k),set<int>());
		graph2d = graph3d;
		while(k--){
			cin >> x >> y >> z;
			if(points3d[{x,y,z}]==0){
				points3d[{x,y,z}]=i;
				i++;
			}
			if(points2d[{x,y}]==0){
				points2d[{x,y}]=j;
				j++;
			}
			id1 = points3d[{x,y,z}];
			id3 = points2d[{x,y}];
			cin >> x >> y >> z;
			if(points3d[{x,y,z}]==0){
				points3d[{x,y,z}]=i;
				i++;
			}
			if(points2d[{x,y}]==0){
				points2d[{x,y}]=j;
				j++;
			}
			id2 = points3d[{x,y,z}];
			id4 = points2d[{x,y}];
			graph3d[id1-1].insert(id2-1);
			graph3d[id2-1].insert(id1-1);
			graph2d[id3-1].insert(id4-1);
			graph2d[id4-1].insert(id3-1);
			//cerr << id1-1 << " " << id2-1 << endl;
			//cerr << id3 << " " << id4 << endl;
		}
		visited.assign(graph3d.size(),0);
		bool ver = 0;
		for(int k=0;k<id2;k++){
			ver|=dfs(k,1,-1);
			//cerr << "*" << endl;
		}
		//cerr << ver << endl;
		if(ver) cout << "True closed chains" << endl;
		else cout << "No true closed chains" << endl;
		//cerr << ":::" << endl;
		visited.assign(graph2d.size(),0);
		ver = 0;
		for(int k=0;k<id4;k++){
			ver|=dfs(k,0,-1);
		}
		//cerr << ver << endl;
		if(ver) cout << "Floor closed chains" << endl;
		else cout << "No floor closed chains" << endl;
		points3d.clear();
		points2d.clear();
	}
	return 0;
}
