#include<bits/stdc++.h>

using namespace std;

int main(){
	double x;
	int xi,n;
	string aux1,aux2;
	cin >> x;
	xi=x*10000;
	vector<string> ns;
	for(int i=1;i<=10000;i++){
		aux1=to_string(i);
		aux2=aux1.substr(1)+aux1[0];
		n=atoi(aux2.c_str());
		n*=10000;
		if(n%xi==0 && (n/xi)==i){
			ns.push_back(aux1);
		}
	}
	if(ns.size()==0){
		cout << "No solution"<< endl;
		return 0;
	}
	for(int i=1;i<=8;i++){
		int j=0;
		while(j<ns.size() && (ns[j].size()*i)<8){
			for(int k=0;k<i;k++)cout <<ns[j];
			cout << endl;
			j++;
		}
	}
	return 0;
}
