#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,pos,c;
	int numerator,denominator;
	while(cin >> n){
		pos = round((ceil(sqrt((8*n)+1))-1)/2);
		
		if(pos&1){
			numerator=pos;
			denominator=1;
			c = -1;
		}
		else{
			numerator = 1;
			denominator = pos;
			c = 1;
		}

		pos = ((pos-1)*(pos))/2;
		pos++;
		
		while(pos<n){
			numerator+=c;
			denominator-=c;
			pos++;
		}
		cout << "TERM " << n << " IS ";
		cout << numerator << "/" << denominator << endl;
	}
	return 0;
}
