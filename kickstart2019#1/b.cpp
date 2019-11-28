#include <bits/stdc++.h>

using namespace std;

vector<string> w;
vector<vector<int>> p;
int r,c;

int run(int x,int y,int cont){
	if(x+1 < r && p[x+1][y]>cont+1 && w[x+1][y]!='1'){
		p[x+1][y]=cont+1;
		run(x+1,y,cont+1);
	}
	if(y+1 < c && p[x][y+1]>cont+1 && w[x][y+1]!='1'){
		p[x][y+1]=cont+1;
		run(x,y+1,cont+1);
	}
	if(x-1 >= 0 && p[x-1][y]>cont+1 && w[x-1][y]!='1'){
		p[x-1][y]=cont+1;
		run(x-1,y,cont+1);
	}
	if(y-1 >=0 && p[x][y-1]>cont+1 && w[x][y-1]!='1'){
		p[x][y-1]=cont+1;
		run(x,y-1,cont+1);
	}
}
int posx,posy;
int res;

int get_ans(){
	int aa=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			aa=max(aa,p[i][j]);
		}
	}
	return aa;
}

void cal(){
	int aux;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(w[i][j]=='1'){
				p[i][j]=0;
				run(i,j,0);
			}
		}
	}
}

void ans(){
	vector<vector<int>> aux=p;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(w[i][j]=='1')continue;
			p[i][j]=0;
			run(i,j,0);
			res=min(res,get_ans());
			p=aux;
		}
	}
}

int main(){
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> r >> c;	
		w.resize(r);
		for(int j=0;j<r;j++)cin >> w[j];
		p.assign(r,vector<int>(c,1e9));	
		cal();
		res=get_ans();
		ans();
		cout << "Case #" << i <<": " << res << endl;
	}
	return 0;
}
