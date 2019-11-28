#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t;
	string s;
	cin >> n >> t;
	cin >> s;
	for(int j=0;j<t;j++){
		for(int i=0;i<s.size();i++){
			if(s[i]=='B'){
				if((i+1)<s.size() && s[i+1]!='B'){
					swap(s[i],s[i+1]);
					i++;
				}
			}
		}
	}
	cout << s << endl;
	return 0;
}
