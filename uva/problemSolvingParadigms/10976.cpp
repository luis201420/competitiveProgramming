#include <bits/stdc++.h>

using namespace std;

typedef int numero;

numero findX(numero &k,numero &y){

	numero v1 = k*y;
	numero v2 = y-k;
	
	if(v1%v2!=0 || (v1/v2)<=0) return -1;
	else return v1/v2;
}

int main(){
	numero k,x;
	vector<string> res;
	while(cin>>k){
		for(numero i=k+1;i<=(2*k);i++){
			x=findX(k,i);
			if(x!=-1){
				res.push_back("1/"+(to_string(x))+" + 1/"+(to_string(i)));
			}
		}
		cout<<res.size()<<endl;
		for(int i=0;i<res.size();i++){
			cout << "1/" << k << " = ";
			cout << res[i] << endl;
		}
		res.clear();
	}
	return 0;
}
