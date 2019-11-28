#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,aux;
	string v;
	cin >> n;
	bool ver=1;
	for(int i=1;i<=n;i++){
		cin >> v;
		if(v=="mumble")continue;
		aux=atoi(v.c_str());
		ver&=(aux==i);
	}
	if(ver)cout << "makes sense";
	else cout << "something is fishy";
	cout << endl;
	return 0;
}
