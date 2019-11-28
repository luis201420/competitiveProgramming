#include <bits/stdc++.h>

using namespace std;

vector<string> grid;

void transf(){
	int acum;
	vector<string> res(3,string(3,'-'));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			//acum=grid[i][j]-'0';
			acum=0;
			if(i+1 < 3){
				acum+=grid[i+1][j]-'0';
			}
			if(j+1 < 3){
				acum+=grid[i][j+1]-'0';
			}
			if(i-1 >= 0){
				acum+=grid[i-1][j]-'0';
			}
			if(j-1 >= 0){
				acum+=grid[i][j-1]-'0';
			}
			res[i][j]=(acum%2)+'0';
		}
	}
	grid=res;
}

int conv(vector<string> & p){
	int res=0,aux;
	for(int i=0;i<p.size();i++){
		aux=0;
		for(int j=0;j<p[i].size();j++){
			if(p[i][j]=='1')aux+=1<<j;
		}
		res+=aux*pow(10,i);
	}
	return res;
}

int main(){
	map<int,int> cont;
	string line;
	int t,cur,res;
	cin >> t;
	while(t--){
		for(int i=0;i<3;i++){
			cin >> line;
			grid.push_back(line);
		}
		cur = conv(grid);
		if(cur == 0) cout << -1 << endl;
		else{
			res = -1;
			//cerr << cur << endl;
			while(cur>0 &&cont[cur]==0){
				cont[cur]++;
				transf();
				cur=conv(grid);
				//cerr << cur << endl;
				res++;
			}
			cout << res << endl;
		}
		cont.clear();
		grid.clear();
	}
	return 0;
}
