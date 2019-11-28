#include <bits/stdc++.h>

using namespace std;

vector<string> board;

char eva(char a,char b){
	if(a=='R' && b =='S')return a;
	if(a=='R' && b =='P')return b;
	if(a=='P' && b =='S')return b;
	if(a=='S' && b =='R')return b;
	if(a=='P' && b =='R')return a;
	if(a=='S' && b =='P')return a;
	if(a==b)return '-';
}

void change(){
	vector<string> aux;
	vector<vector<bool>> ver(board.size(),vector<bool>(board[0].size(),0));
	aux = board;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if((j+1)<board[i].size() && eva(board[i][j],board[i][j+1])==board[i][j] && !ver[i][j+1]){aux[i][j+1]=eva(board[i][j],board[i][j+1]);ver[i][j+1]=1;}
			if((i+1)<board.size() && eva(board[i][j],board[i+1][j])==board[i][j] && !ver[i+1][j]){aux[i+1][j]=eva(board[i][j],board[i+1][j]);ver[i+1][j]=1;}
			if((j-1)>=0 && eva(board[i][j],board[i][j-1])==board[i][j] && !ver[i][j-1]){aux[i][j-1]=eva(board[i][j],board[i][j-1]);ver[i][j-1]=1;}
			if((i-1)>=0 && eva(board[i][j],board[i-1][j])==board[i][j] && !ver[i-1][j]){aux[i-1][j]=eva(board[i][j],board[i-1][j]);ver[i-1][j]=1;}
		}
	}
	board=aux;
}

int main(){
	int t;
	int r,c,n;
	string line;
	cin >> t;
	for(int i=0;i<t;i++){
		if(i!=0)cout<<endl;
		cin >> r >> c >> n;
		while(r--){
			cin >> line;
			board.push_back(line);
		}
		if(r!=0 && c!=0){
			for(int j=0;j<n;j++)change();
			for(int j=0;j<board.size();j++){
				cout << board[j]<<endl;
			}
		}
		board.clear();
	}
	return 0;
}
