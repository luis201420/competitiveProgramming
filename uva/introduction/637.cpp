#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,s,r,cont1,cont2;
	while(cin >> n){
		if(n==0)break;
		r=(4-(n%4))%4;
		s = (n+r)/4;
		cout << "Printing order for " << n << " pages:"<<endl;
		cont1=1;cont2=n;
		for(int i=1;i<=s;i++){
			cout << "Sheet "<<i << ", front: ";
		       	if(r){ cout << "Blank";r--;}
			else cout << cont2--;
			cout << ", " << cont1++<< endl;
			if(cont1>n) break;
			cout << "Sheet "<<i << ", back : "<< cont1++ << ", ";
			if(r){cout << "Blank";r--;}
			else cout << cont2--;
			cout<< endl;
		}
	}
	return 0;
}
