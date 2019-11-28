#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> k(4);
	for(int i=0;i<4;i++){
		cin >> k[i];
	}
	int cont1 = 0;
	while(k[0]>0 && k[2]>0 && k[3]>0){
		k[0]--;k[2]--;k[3]--;
		cont1++;
	}
	int cont2 = 0;
	while(k[0]>0 && k[1]>0){
		k[0]--;k[1]--;
		cont2++;
	}
	cout << 256*cont1+32*cont2 << endl;
	return 0;
}
