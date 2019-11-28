#include <bits/stdc++.h>

using namespace std;

#define N 26
vector<vector<int>> distY,distM;

void warshall(){
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				distY[i][j]=min(distY[i][j],distY[i][k]+distY[k][j]);
				distM[i][j]=min(distM[i][j],distM[i][k]+distM[k][j]);
			}
		}
	}
}

int main(){
	vector<int> id_res;
	int s,c,dist_res,aux;
	char t,d,x,y;
	while(cin >> s){
		if(s == 0) break;
		distY.assign(N,vector<int>(N,1e9));
		distM = distY;
		for(int i=0;i<N;i++){
			distY[i][i]=distM[i][i]=0;
		}
		while(s--){
			cin >> t >> d >> x >> y >> c;
			if(x==y)continue;
			x-='A'; y-='A';
			if(t == 'Y'){
				distY[x][y]=c;
				if(d == 'B') distY[y][x]=c;
			}
			if(t == 'M'){
				distM[x][y]=c;
				if(d == 'B')distM[y][x]=c;
			}
		}
		warshall();
		cin >> x >> y;
		x-='A';y-='A';
		dist_res=1e9;
		for(int i=0;i<N;i++){
			aux = (distY[x][i]+distM[y][i]);
			if(aux<dist_res){
				id_res.clear();
				id_res.push_back(i);
				dist_res=aux;
			}
			else if(aux == dist_res){
				id_res.push_back(i);
			}
		}
		if(dist_res<1e9){
			cout << dist_res;
			for(int i=0;i<id_res.size();i++)cout <<" "<<char('A'+id_res[i]);
			cout << endl;
		}
		else
			cout << "You will never meet."<<endl;
	}
	return 0;
}
