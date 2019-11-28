#include <bits/stdc++.h>

using namespace std;

bool ver(string x){
	if(x=="2")return 1;
	if(x=="12")return 1;
	char l = x[x.size()-1];
	char f = x[0];
	if(l=='9' || l=='7' || l=='1')return 0;
	if(f=='2' ||f=='9' || f=='7' || f=='1')return 0;
	return 1;
}

int main(){
	string s;
	cin >> s;
	if(!ver(s))cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
