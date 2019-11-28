#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dist;
int n;

void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
	int k;
	int a,b,l;
	cin >> n >> k;
	dist.assign(n,vector<int>(n,1e9));
	for(int i=0;i<k;i++){
		cin >> a >>  b >> l;
		dist[a-1][b-1]=l;
		dist[a-1][a-1]=0;
		dist[b-1][b-1]=0;
	}
	floyd();
	double res = 0.0;
	int cont = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]<1e9 && dist[i][j]>0){
				res+=dist[i][j];
				cont++;
			}
		}
	}
	cout << setprecision(6) << fixed;
	cout << res/double(cont) << endl;
	return 0;
}
