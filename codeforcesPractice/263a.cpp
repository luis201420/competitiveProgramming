#include <bits/stdc++.h>

using namespace std;

int main(){
	int v,res;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> v;
			if(v==1)res = abs(2-i)+abs(2-j);
		}
	}
	cout << res << endl;
	return 0;
}
