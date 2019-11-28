#include <bits/stdc++.h>

using namespace std;

int main(){
	int v,k,s,ant;
	cin >> v;
	s=0;
	ant=v;
	for(int i=0;i<4;i++){
		cin >> v;
		s+=(v-ant);
		ant=v;
	}
	cin >> k;
	if(s>k) cout << ":(" << endl;
	else cout << "Yay!" << endl;
	return 0;
}
