#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;

int m;

void cal(int a,int b){
	queue<pair<int,pair<int,int>>> q;
	board[a][b]=0;
	q.push({0,{a,b}});
	int c;
	while(!q.empty()){
		a=(q.front().second).first; b=(q.front().second).second;
		c=q.front().first;
		m=max(m,c);
		q.pop();
		if(a+2<8 && b+1<8 && board[a+2][b+1]==-1){
			board[a+2][b+1]=c+1;
			q.push({c+1,{a+2,b+1}});
		}
		if(a-2>=0 && b+1<8 && board[a-2][b+1]==-1){
			board[a-2][b+1]=c+1;
			q.push({c+1,{a-2,b+1}});
		}
		if(a+2<8 && b-1>=0 && board[a+2][b-1]==-1){
			board[a+2][b-1]=c+1;
			q.push({c+1,{a+2,b-1}});
		}
		if(a-2>=0 && b-1>=0 && board[a-2][b-1]==-1){
			board[a-2][b-1]=c+1;
			q.push({c+1,{a-2,b-1}});
		}
	
		if(a+1<8 && b+2<8 && board[a+1][b+2]==-1){
			board[a+1][b+2]=c+1;
			q.push({c+1,{a+1,b+2}});
		}
		if(a+1<8 && b-2>=0 && board[a+1][b-2]==-1){
			board[a+1][b-2]=c+1;
			q.push({c+1,{a+1,b-2}});
		}
		if(a-1>=0 && b+2<8 && board[a-1][b+2]==-1){
			board[a-1][b+2]=c+1;
			q.push({c+1,{a-1,b+2}});
		}
		if(a-1>=0 && b-2>=0 && board[a-1][b-2]==-1){
			board[a-1][b-2]=c+1;
			q.push({c+1,{a-1,b-2}});
		}
	}
}

int main(){
	int t;
	int x,y;
	string p;
	cin >> t;
	while(t--){
		board.assign(8,vector<int>(8,-1));
		cin >> p;
		x=8-(p[1]-'0');
		y=p[0]-'a';
		m=0;
		cal(x,y);
		cout << m;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(board[i][j]==m)
					cout<<" " << char(j+'a') << 8-i;
			}
		}
		cout << endl;
	}
	return 0;
}
