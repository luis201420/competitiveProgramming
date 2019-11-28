#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,v;
	int cont1P,cont1I,cont2P,cont2I;
	cin >> n >> m;
	cont1P = cont1I = cont2P = cont2I = 0;
	for(int i=0;i<n;i++){
		cin >> v;
		if(v&1)cont1I++;
		else cont1P++;
	}
	for(int i=0;i<m;i++){
		cin >> v;
		if(v&1)cont2I++;
		else cont2P++;
	}
	cout << min(cont1I,cont2P)+min(cont1P,cont2I) << endl;
	return 0;
}
