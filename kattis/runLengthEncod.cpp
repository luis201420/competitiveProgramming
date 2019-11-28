#include <bits/stdc++.h>

using namespace std;

int main(){
	char op;
	string line,res="";
	cin >> op >> line;
	if(op == 'E'){
		int j;
		for(int i=0;i<line.size();i++){
			res+=line[i];
			j=i+1;
			while(j<line.size() && line[i]==line[j]){
				j++;
			}
			res+=to_string(j-i);
			i=j-1;
		}
	}
	else{
		for(int i=0;i<line.size();i+=2){
			res+=string((line[i+1]-'0'),line[i]);
		}
	}
	cout << res << endl;
	return 0;
}
