#include <bits/stdc++.h>

using namespace std;

int res;
vector<vector<bool>> board;

void dfs(string a,string b,int c){
	if(a==b){
		res=min(res,c);
		return;
	}
	cerr << a  << " " << c <<" " <<  res<< endl;
	if(((a[0]+2)<='h' && (a[1]+1)<='8') && !(board[(a[0]+2)-'a'][(a[1]+1)-'0'])){
		board[(a[0]+2)-'a'][(a[1]+1)-'0']=1;
		dfs(string(1,a[0]+2)+string(1,a[1]+1),b,c+1);
		board[(a[0]+2)-'a'][(a[1]+1)-'0']=0;
	}
	if(((a[0]-2)>='a' && (a[1]-1)>='0') && !(board[(a[0]-2)-'a'][(a[1]-1)-'0'])){
		board[(a[0]-2)-'a'][(a[1]-1)-'0']=1;
		dfs(string(1,a[0]-2)+string(1,a[1]-1),b,c+1);
		board[(a[0]-2)-'a'][(a[1]-1)-'0']=0;
	}
	if(((a[0]+2)<='h' && (a[1]-1)>='0') && !(board[(a[0]+2)-'a'][(a[1]-1)-'0'])){
		board[(a[0]+2)-'a'][(a[1]-1)-'0']=1;
		dfs(string(1,a[0]+2)+string(1,a[1]-1),b,c+1);
		board[(a[0]+2)-'a'][(a[1]-1)-'0']=0;
	}
	if(((a[0]-2)>='a' && (a[1]+1)<='8') && !(board[(a[0]-2)-'a'][(a[1]+1)-'0'])){
		board[(a[0]-2)-'a'][(a[1]+1)-'0']=1;
		dfs(string(1,a[0]-2)+string(1,a[1]+1),b,c+1);
		board[(a[0]-2)-'a'][(a[1]+1)-'0']=0;
	}
	if(((a[0]+1)<='h' && (a[1]+2)<='8') && !(board[(a[0]+1)-'a'][(a[1]+2)-'0'])){
		board[(a[0]+1)-'a'][(a[1]+2)-'0']=1;
		dfs(string(1,a[0]+1)+string(1,a[1]+2),b,c+1);
		board[(a[0]+1)-'a'][(a[1]+2)-'0']=0;
	}
	if(((a[0]-1)>='a' && (a[1]-2)>='0') && !(board[(a[0]-1)-'a'][(a[1]-2)-'0'])){
		board[(a[0]-1)-'a'][(a[1]-2)-'0']=1;
		dfs(string(1,a[0]-1)+string(1,a[1]-2),b,c+1);
		board[(a[0]-1)-'a'][(a[1]-2)-'0']=0;
	}
	if(((a[0]+1)<='h' && (a[1]-2)>='0') && !(board[(a[0]+1)-'a'][(a[1]-2)-'0'])){
		board[(a[0]+1)-'a'][(a[1]-2)-'0']=1;
		dfs(string(1,a[0]+1)+string(1,a[1]-2),b,c+1);
		board[(a[0]+1)-'a'][(a[1]-2)-'0']=0;
	}
	if(((a[0]-1)>='a' && (a[1]+2)<='8') && !(board[(a[0]-1)-'a'][(a[1]+2)-'0'])){
		board[(a[0]-1)-'a'][(a[1]+2)-'0']=1;
		dfs(string(1,a[0]-1)+string(1,a[1]+2),b,c+1);
		board[(a[0]-1)-'a'][(a[1]+2)-'0']=0;
	}
	return;
}

int main(){
	string s1,s2;
	while(cin >> s1 >> s2){
		board.assign(8,vector<bool>(8,0));
		res=1e9;
		dfs(s1,s2,0);
		cout << res << endl;
	}
	return 0;
}
