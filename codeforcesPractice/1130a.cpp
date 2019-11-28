#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v,cont1,cont2;
	cin >> n;
	cont1=cont2=0;
	for(int i=0;i<n;i++){
		cin >> v;
		if(v>0)cont2++;
		if(v<0)cont1++;
	}
	if(cont2>=ceil(float(n)/2.0)){
		cout << 2 << endl;
	}
	else if(cont1>=ceil(float(n)/2.0)){
		cout << -2 << endl;
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}
