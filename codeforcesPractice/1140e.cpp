#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,k,v;
	int cont1,cont2;
	set<int> s1,s2;
	cont1=cont2=0;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> v;
		if(i&1){
			if(v==-1)cont1++;
			if(v>0 && v<k)s1.insert(v);
		}
		else{
			if(v==-1)cont2++;
			if(v>0 && v<k)s2.insert(v);
		}
	}
	int r1=1;
	if(cont1>0){
		
	}
	int r2=1;
	if(cont2>0){
	
	}
	return 0;
}
