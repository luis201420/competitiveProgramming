#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,v,res,x,y;
	cin >> n;
	vector<pair<int,int>> pos;
	vector<vector<bool>> ver;
	bool s;
	while(n--){
		ver.assign(5,vector<bool>(5,0));
		pos.assign(76,pair<int,int>(-1,-1));
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i==2 && j==2)continue;
				cin >> v;
				pos[v]={i,j};
			}
		}
		ver[2][2]=1;
		res=-1;
		for(int i=0;i<75;i++){
			cin >> v;
			x=pos[v].first;
			y=pos[v].second;
			if(x == -1 && y == -1) continue;
			//cerr << v <<" "<< x << " " << y << endl;
			ver[x][y]=1;
			if(res==-1){
				s=1;
				for(int j=0;j<5;j++){
					s&=ver[x][j];
				}
				if(s)res=i;
			}
			if(res==-1){
				if(s)res=i;
				s=1;
				for(int j=0;j<5;j++){
					s&=ver[j][y];
				}
				if(s)res=i;
			}
			if(res==-1){
				s=1;
				for(int j=0;j<5;j++){
					s&=ver[j][j];
				}
				if(s)res=i;
			}
			if(res == -1){
				s=1;
				for(int j=0;j<5;j++){
					s&=ver[4-j][j];
				}
				if(s)res=i;
			}
		}
		cout << "BINGO after " << res+1 << " numbers announced" << endl;
	}
	return 0;
}
