#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v,cont1,cont2;
	cont1=cont2=0;
	cin>>n;
	while(n--){
		cin >> v;
		if(v==5) cont1++;
		if(v==0) cont2++;
	}

	if(cont2>0){

		int res = cont1-(cont1%9);
		if(res==0) cout << 0 << endl;
		else{
			while(res--) cout << 5;
			while(cont2--) cout << 0;
			cout << endl;
		}
	}
	else cout << -1 << endl;
	return 0;
}
