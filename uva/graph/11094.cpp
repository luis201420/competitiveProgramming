#include <bits/stdc++.h>

using namespace std;

vector<string> my_map;
int n,m,cont;
char water,land;

void dfs(int a,int b){
	cont++;
	//cerr << a << " " << b << endl;
	my_map[a][b]=water;
	if((a+1)<m && my_map[a+1][b]==land)dfs(a+1,b);
	if(my_map[a][(b+1)%n]==land)dfs(a,(b+1)%n);
	if((a-1)>=0 && my_map[a-1][b]==land)dfs(a-1,b);
	if(my_map[a][(b-1+n)%n]==land)dfs(a,(b-1+n)%n);
}

int main(){
	int x,y,res;
	string line;
	while(cin >> m >> n){
		for(int i=0;i<m;i++){
			cin >> line;
			my_map.push_back(line);
		}
		water=' ';
		cin >> x >> y;
		land=my_map[x][y];
		/*for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(my_map[i][j]!=land){
					water=my_map[i][j];
					j=n;i=m;
				}
			}
		}*/
	
		cont=0;
		dfs(x,y);
		res = 0;
		//cerr << "*" << endl;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(my_map[i][j]==land){
					cont=0;
					dfs(i,j);
					//cerr << cont << endl;
					if(res<cont)res=cont;
				}
			}
		}
		cout << res << endl;
		my_map.clear();
	}
	return 0;
}
