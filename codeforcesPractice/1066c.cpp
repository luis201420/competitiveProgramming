#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,p;
	char c; int id;
	map<int,int> pos;
	int li=0,ri=1;
	
	cin >> n;
	while(n--){
		cin >> c >> id;
		if(c=='L'){
			pos[id]=li--;
		}
		else if(c=='R'){
			pos[id]=ri++;
		}
		else{
			cout << min(pos[id]-li-1,ri-pos[id]-1) << endl;
		}
	}
	return 0;
}
