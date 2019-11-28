#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,c;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		bool ver = 0;
		for(int x=(-b);x<=(b);x++){
			if(x==0 || b%x!=0) continue;
			for(int y=(-b);y<=(b);y++){
				if(y == 0 || b%y!=0) continue;
				int z = b/(x*y);
				//cerr << x << " " << y << " " << z << endl;
				if((x!=y && y!=z && x!=z) && (x*y*z)==b && ((x*x)+(y*y)+(z*z))==c && (x+y+z)==a){
					cout << x << " " << y << " " << z << endl;
					x=y=(b+1);
					ver = 1;
				}
			}
		}
		if(!ver)cout << "No solution."<< endl;
	}
	return 0;
}
