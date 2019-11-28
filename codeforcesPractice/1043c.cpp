#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,aux;
	bool ver;
	cin >> s;
	cout << 0 << " ";
	for(int k=1;k<s.size();k++){
		if(s[0]>s[k]){
			aux = s.substr(0,k+1);
			reverse(aux.begin(),aux.end());
			s=aux+s.substr(k+1);
			cout << 1 << " ";
		}
		else{
			ver=0;
			for(int i=k+1;i<s.size();i++){
				if(s[i]<s[k]){
					ver=1;
					break;
				}
			}
			if(ver){
				aux = s.substr(0,k+1);
	                        reverse(aux.begin(),aux.end());
	                        s=aux+s.substr(k+1);
	                        cout << 1 << " ";
			}
			else{
				cout << 0 << " ";
			}
		}
	}
	cout << endl;
	return 0;
}
