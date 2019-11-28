#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	if(m%n==0){
		int cont = 0;
		int r = m/n;
		while(r%2==0){
			r/=2;
			cont++;
		}
		while(r%3==0){
			r/=3;
			cont++;
		}
		if(r==1)
			cout << cont << endl;
		else 
			cout << -1 << endl;
	}
	else cout << -1 << endl;
	return 0;
}
