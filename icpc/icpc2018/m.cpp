#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v,ant=0,res=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		if((ant-v)>=0)res++;
		ant=v;
	}
	cout << n-res << endl;
	return 0;
}
