#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,r;
	cin >> s;
	r="";
	int i,j;
	if(s.size()&1){
		i=0;
		j=s.size()-1;
		while(i<=j){
			r=s[i]+r;
			if(i!=j)r=s[j]+r;
			i++;
			j--;
		}
	}
	else{
		i=s.size()-1;
		j=0;
		while(j<=i){
			r=s[i]+r;
			if(i!=j)r=s[j]+r;
			i--;
			j++;
		}
	}
	cout << r << endl;
	return 0;
}
