#include <bits/stdc++.h>

using namespace std;

typedef set<char> SC;

int main(){
	string s;
	SC cont;
	cin >> s;
	for(char c:s)cont.insert(c);
	if(cont.size()&1) cout << "IGNORE HIM!";
	else cout << "CHAT WITH HER!"; 
	cout << "\n";
	return 0;
}
