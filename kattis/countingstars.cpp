#include <bits/stdc++.h>

using namespace std;

vector<string> sky;
int n,m;

void fillStar(int x,int y){
	if(x+1 < n && sky[x+1][y]=='-'){
		sky[x+1][y]='#';
		fillStar(x+1,y);
	}
	if(y+1 < m && sky[x][y+1]=='-'){
		sky[x][y+1]='#';
		fillStar(x,y+1);
	}
	if(x-1 >= 0 && sky[x-1][y]=='-'){
		sky[x-1][y]='#';
		fillStar(x-1,y);
	}
	if(y-1 >= 0 && sky[x][y-1]=='-'){
		sky[x][y-1]='#';
		fillStar(x,y-1);
	}
}

int main(){
	int res,test=1;
	while(cin >> n >> m){
		sky.resize(n);
		for(int i=0;i<n;i++)
			cin >> sky[i];
		res=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(sky[i][j]=='-'){
					fillStar(i,j);
					res++;
				}
			}
		}
		cout <<"Case "<<test++ <<": "<< res << endl;
	}
	return 0;
}
