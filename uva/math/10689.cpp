#include <bits/stdc++.h>

using namespace std;

struct Matrix{
	long long a,b,c,d;
};

Matrix multi(const Matrix &m1,const Matrix &m2,long long di){
	Matrix res;
	res.a = ((m1.a*m2.a)%di) + ((m1.b*m2.c)%di)%di;
	res.b = ((m1.a*m2.b)%di) + ((m1.b*m2.d)%di)%di;
	res.c = ((m1.c*m2.a)%di) + ((m1.d*m2.c)%di)%di;
	res.d = ((m1.c*m2.b)%di) + ((m1.d*m2.d)%di)%di;
	return res;
}

Matrix modM(Matrix m2,long long di){
	Matrix m1=m2;
	m1.a%=di;
	m1.b%=di;
	m1.c%=di;
	m1.d%=di;
	return m1;
}

Matrix binpow(Matrix x,long long y,long long d){
	x=modM(x,d);
	Matrix res = {0,1,1,1};
	while(y>0){
		if(y&1)
			res=modM(multi(res,x,d),d);
		x=modM(multi(x,x,d),d);
		y>>=1;
	}
	return res;
}

int main(){
	Matrix p,res,q;
	long long t;
	long long i,j,n,m;
	long long aux;
	cin >> t;
	while(t--){
		cin >> i >> j >> n >> m;
		if(n==0){
			cout << i << endl;
			continue;
		}
		p = {0,1,1,1};
		q = {i,j,j,i+j};
		aux=pow(10,m);
		res = binpow(p,n-1,aux);
		//cerr << res.a << " " << res.b << " " << res.c << " " << res.d << endl;
		cout << modM(multi(q,res,aux),aux).a << endl;
	}
	return 0;
}
