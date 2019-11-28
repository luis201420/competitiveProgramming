#include <bits/stdc++.h>

using namespace std;

typedef double t_number;

int main(){
	int n;
	t_number res,x,y,sum1,sum2;
	vector<t_number> Sx,Sy;
	cin>>n;
	while(n--){
		cin>>x>>y;
		Sx.push_back(x);
		Sy.push_back(y);
	}
	
	sum1=0;
	for(unsigned i=0;i<Sy.size()-1;i++){
		sum1+=Sx[i]*Sy[i+1];
	}
	sum2=0;
        for(unsigned i=0;i<Sx.size()-1;i++){
                sum2+=Sx[i+1]*Sy[i];
        }

	res = abs(sum1 + (Sx[Sx.size()-1]*Sy[0]) - sum2 - (Sx[0]*Sy[Sy.size()-1]));
	res/=2;
	cout << setprecision(3)<< fixed;
	cout << res << endl;
	return 0;
}
