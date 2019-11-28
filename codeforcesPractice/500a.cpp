#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,q,v;
	bool res=0;
	cin >> n >> q;
	int r = 1;
	for(int i=1;i<n;i++){
		cin >> v;	
		if(r==q)res=1;
		if(r==i)r=(v+r);
	}
	if(r==q)res=1;
	if(res)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
