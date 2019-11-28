#include <bits/stdc++.h>

using namespace std;

int main(){
	string line,res;
	cin >> line;
	res=line[0];
	for(int i=0;i<line.size();i++){
		if(line[i]=='-')res+=line[i+1];
	}
	cout << res << endl;
	return 0;
}
