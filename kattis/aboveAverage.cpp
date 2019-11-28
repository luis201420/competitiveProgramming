#include<bits/stdc++.h>

using namespace std;

int main(){
	int c,n;
	cin >> c;
	vector<double> ns;
	float avrg;
	int cont;
	cout << setprecision(3) << fixed;
	while(c--){
		cin >> n;
		ns.resize(n);
		avrg=0;
		for(int i=0;i<n;i++){
			cin >> ns[i];
			avrg+=ns[i];
		}
		avrg/=double(n);
		cont=0;
		for(int i=0;i<n;i++){
			if(ns[i]>avrg)cont++;
		}
		cout << round((double(cont*100.0)/double(n))*1000.0)/1000.0 << "%" << endl;
	}
	return 0;
}
