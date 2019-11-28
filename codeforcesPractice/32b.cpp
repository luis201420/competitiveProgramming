#include <bits/stdc++.h>
using namespace std;

int main(){
	string code,decode;
	cin >> code;

	decode="";
	for(int i=0;i<code.size();i++){
		if(code[i]=='.')decode+='0';
		else{
			if((i+1)<code.size() && code[i+1]=='-')decode+='2';
			else decode+='1';
			i++;
		}
	}
	cout << decode << endl;
	return 0;
}
