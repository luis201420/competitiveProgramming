#include <bits/stdc++.h>

using namespace std;

bool ver(int x){
	vector<bool> ver(10,0);
	int a=-1,aux;
	while(x>0){
		if(ver[x%10])return 0;
		ver[x%10]=1;
		x=(x-(x%10))/10;
	}
	return 1;
}

int main(){
	int n,m,res;
	while(cin >>n >> m){
		res=0;
		for(;n<=m;n++){
			res+=ver(n);
		}
		cout << res << endl;
	}
	return 0;
}
