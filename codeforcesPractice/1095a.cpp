#include <bits/stdc++.h>

using namespace std;

int main(){
	string t,res;
	int n,cont;
	cin >> n >> t;
	res="";
	cont=1;
	for(int i=0;i<t.size();i++){
		res+=t[i];
		i+=cont;
		cont++;
	}
	cout << res << endl;
	return 0;
}
