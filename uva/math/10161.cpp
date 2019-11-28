#include <bits/stdc++.h>

using namespace std;

int main(){
	double n,dif;
	int pos,s;
	while(cin >> n){
		if(n == 0) break;

		pos = ceil(sqrt(n));
		s = (pos*2)-1;
		
		dif=n-(((pos-1)*(pos-1)));

		//cerr << pos << "-" << dif << endl;

		if((s-1)%4==0){ //1 n
			if(dif<pos){
				cout << pos << " " << dif;
			}
			else{
				cout << pos-(dif-pos) << " " << pos;
			}
		}
		
		else { // n 1
			if(dif<pos){
				cout << dif << " " << pos;
			}
			else{
				cout << pos << " " << pos-(dif-pos);
			}
		}

		cout << endl;
	}
	return 0;
}
