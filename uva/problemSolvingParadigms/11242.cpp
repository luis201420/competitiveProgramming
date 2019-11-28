#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	float v,g,aux;
	vector<float> f,ord;
	while(cin >> n){
		if(n==0) break;
		cin >> m;
		while(n--){
			cin >> v;
			f.push_back(v);
		}

		while(m--){
			cin >> v;
			for(int i=0;i<f.size();i++){
				ord.push_back(v/f[i]);
			}
		}
		sort(ord.begin(),ord.end(),greater<float>());
		
		g=-1;
		for(int i=0;i<ord.size()-1;i++){
			aux=(ord[i]/ord[i+1]);
			//cerr << aux << endl;
			if(g<aux)g=aux;
		}

		printf("%.2f\n",roundf(g*100)/100);
		ord.clear();
		f.clear();
	}
	return 0;
}
