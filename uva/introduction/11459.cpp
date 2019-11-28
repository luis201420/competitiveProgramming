#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> board,pos;
	int t,a,b,c,p,q,d;
	cin >> t;
	for(int j=1;j<=t;j++){
		board.assign(101,-1);
		cin >> a >> b >> c;
		pos.assign(a,1);
		while(b--){
			cin >> p >> q;
			board[p]=q;
		}
		bool v=1;
		for(int i=0;i<c;i++){
			cin >> d;
			if(v && a!=0){
				pos[i%a]+=d;
				if(pos[i%a]>100)pos[i%a]=100;
				if(board[pos[i%a]]!=-1)pos[i%a]=board[pos[i%a]];
				if(pos[i%a]==100)v=0;
			}
		}
		for(int i=0;i<a;i++){
			cout << "Position of player "<<i+1 <<" is "<<pos[i] <<"."<< endl;
		}
	}
	return 0;
}
