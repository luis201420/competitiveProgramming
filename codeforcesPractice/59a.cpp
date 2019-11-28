#include <bits/stdc++.h>

using namespace std;

int main(){
	int cont1,cont2;
	string s;
	cin >> s;
	cont1=cont2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a' && s[i]<='z')cont1++;
		else cont2++;
	}
	for(int i=0;i<s.size();i++){
		if(cont1>=cont2)s[i]=tolower(s[i]);
		else s[i]=toupper(s[i]);
	}
	cout << s << endl;
	return 0;
}
