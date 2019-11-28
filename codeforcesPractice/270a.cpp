#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t,a;
	
	cin>>t;

	while(t--){
		
		cin>>a;

		if(360%(180-a)==0) cout << "YES";
		else cout << "NO";

		cout << endl;
	}
	return 0;
}
