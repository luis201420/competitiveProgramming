#include <bits/stdc++.h>

using namespace std;

vector<char> names;
vector<int> users;
vector<vector<int>> comps,adj;
vector<bool> visited;
vector<int> match;

bool aug(int ini){
	if(visited[ini])return 0;
	visited[ini]=1;
	for(int i=0;i<adj[ini].size();i++){
		int r = adj[ini][i];
		if(match[r] == -1 || aug(match[r])){
			match[r]=ini;
			return 1;
		}
	}
	return 0;
}

int main(){
	int cont,comp,res,tot;
	string line,aux;	

	while(1){
		cont = tot= 0;
		while(getline(cin,line)){
			if(line=="")break;
			aux="";
			int i=0;
			while(line[i]!=' '){
				aux+=line[i];
				i++;
			}
			i++;
			names.push_back(aux[0]);
			users.push_back( atoi((aux.substr(1)).c_str() ) );
			tot += atoi((aux.substr(1)).c_str() ); 
			comps.push_back(vector<int>());
			
			while(i<line.size()-1){
				comps[cont].push_back(line[i]-'0');
				i++;
			}

			cont++;
		}
		if(cont == 0) break;
		//cerr << tot << endl;
		adj.assign(tot,vector<int>());
		comp = 0;
		for(int i=0;i<names.size();i++){
			for(int j=0;j<users[i];j++){
				for(int k=0;k<comps[i].size();k++){
					adj[comp+j].push_back(comps[i][k]);
				}
			}
			comp+=users[i];
		}
		match.assign(10,-1);
		res=0;
		for(int i=0;i<adj.size();i++){
			visited.assign(adj.size(),0);
			res+=aug(i);
		}
		
		if(res!=tot) cout << "!";
		else{
			for(int i=0;i<match.size();i++){
				if(match[i]==-1){
					cout<<"_";
					continue;
				}
				int j=0,acum=0;
				while(j<users.size() && (acum+users[j])<=match[i]){
					acum+=users[j];
					j++;
				}
				cout << names[j];
			}
		}
		cout << endl;
		names.clear();
		users.clear();
		comps.clear();
	}
	return 0;
}
