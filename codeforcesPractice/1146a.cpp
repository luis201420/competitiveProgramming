#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int cont = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a')cont++;
	}
	if(cont>s.size()/2)cout << s.size();
	else cout << (cont*2)-1;
	cout << endl;
	return 0;
}
