#include <bits/stdc++.h>

using namespace std;

int main(){
	char c;
	int t,n,m;
	cin >> t;
	while(t--){
		cin >> c >> m >> n;
		if(c=='r'){
			cout << min(m,n);
		}
		else if(c=='K'){
			cout << ceil(m/2.0)*ceil(n/2.0);
		}
		else if(c=='k'){
			cout << ceil((m*n)/2.0);
		}
		else{
			cout << min(m,n);
		}
		cout << endl;
	}
        return 0;
}
