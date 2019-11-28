#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	char ini = s[0];
	int cont = 0;
	for(int i=1;i<s.size();i++){
		if(ini!=s[i]){ini=s[i];cont++;}
		if(ini!='U'){ini='U';cont++;}
	}
	cout << cont << endl;
	cont = 0;
	ini = s[0];
	for(int i=1;i<s.size();i++){
		if(ini!=s[i]){ini=s[i];cont++;}
		if(ini!='D'){ini='D';cont++;}
	}
	cout << cont << endl;
	cont = 0;
	ini = s[0];
	for(int i=1;i<s.size();i++){
		if(ini!=s[i]){ini=s[i];cont++;}
		//if(ini!='D'){ini='D';cont++;}
	}
	cout << cont << endl;
	return 0;
}
