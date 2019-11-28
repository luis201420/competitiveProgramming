#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int res=0;
	for(int i=1;i<=(n-2);i++){
		res+=1*(n-i)*(n-i+1);
	}
	cout << res << endl;
	return 0;
}
