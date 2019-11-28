#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,x,b,y;
	cin >> n >> a >> x >> b >> y;
	vector<int> p1,p2;
	while(a!=x){
		p1.push_back(a);
		if(a<n)a++;
		else a=1;
	}
	p1.push_back(x);
	while(b!=y){
		p2.push_back(b);
		if(b>1)b--;
		else b=n;
	}
	p2.push_back(y);
	bool ver=0;
	for(int i=0;i<min(p1.size(),p2.size());i++){
		if(p1[i]==p2[i])ver=1;
	}
	if(ver)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
