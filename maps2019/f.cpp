#include<bits/stdc++.h>

using namespace std;

vector<double> vs; 

#define MPI 3.141592653589793

void precal(){
	double a=1,b=4;
	vs.push_back(a/b);
	a*=3;b*=4;
	for(int i=1;i<50;i++){
		vs.push_back(vs[i-1]+(a/b));
		a*=3;
		b*=4;
	}
}

int main(){
	precal();
	double t,n,r;
	cin>> t;
	double res;
	cout << setprecision(12) << fixed;
	while(t--){
		cin >> r >> n;
		res=(MPI)*(r*r); 
		if(n==1)cout <<res << endl;
		else{
		       	cout << ((4*res)*vs[n-2])+res << endl;
		}
	}
	return 0;
}
