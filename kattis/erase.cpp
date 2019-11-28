#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	bool ver = 1;
	for(int i=0;i<a.size();i++){
		if(n&1){
			ver&=(a[i]!=b[i]);
		}
		else{
			ver&=(a[i]==b[i]);
		}
	}
	if(ver)cout << "Deletion succeeded";
	else cout << "Deletion failed";
	cout << endl;
	return 0;
}
