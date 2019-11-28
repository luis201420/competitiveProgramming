#include <bits/stdc++.h>

using namespace std;

int main(){
	int q,l1,l2,r1,r2;
	
	cin >> q;
	while(q--){
		cin >> l1 >> r1 >> l2 >> r2;
		for(;l1<=r1;l1++){
			for(;l2<=r2;l2++){
				if(l1!=l2){
					cout << l1 <<" "<< l2 << endl;
					l1=r1+1;
					l2=r2+1;
				}
			}
		}
	}
	return 0;
}
