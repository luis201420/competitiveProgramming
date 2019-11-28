#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	string s1,s2;
	cin >> s1 >> s2;
	int cont=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i])cont++;
	}
	if(cont > k){
		cout << k + ((s1.size()-k)-(cont-k)) << endl;
	}
	else{
		cout << cont + (s1.size()-k) << endl;
	}
	return 0;
}
