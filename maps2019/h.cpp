#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	bool v;
	int cont=0,res=0;
	for(int i=0;i<b.size();i++){
		v=0;
		for(int j=0;j<a.size();j++){
			if(b[i]==a[j]){
				v=1;
				res++;
			}
		}
		if(!v)cont++;

		if(res==a.size()){
			cout << "WIN" << endl;
			break;
		}
		if(cont >= 10){
			cout << "LOSE" << endl;
			break;
		}
	}
	return 0;
}
