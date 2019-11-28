#include <bits/stdc++.h>

using namespace std;

const int MODE = 1e9+7;

vector<int> links,sizes;

struct Edge{
	int u,v,w;
};

vector<Edge> edges;

int finds(int x){
	if(x == links[x]) return x;
	return links[x]=finds(links[x]);
}

bool same(int x,int y){
	return finds(x) == finds(y);
}

void unite(int x,int y){
	x=finds(x);
	y=finds(y);
	if(sizes[x]<sizes[y])swap(x,y);
	sizes[x]+=sizes[y];
	links[y]=x;
}

void cal(){
	for(auto it:edges){
		cerr << it.u << " " << it.v << " " << it.w << endl;
		if(it.w==0){
			unite(it.u,it.v);
		}
	}
}

long long binpow(long long a,long long b){
	a %= MODE;
    	long long res = 1;
   	while (b > 0) {
       		if (b & 1)
            		res = res * a % MODE;
        	a = a * a % MODE;
       		b >>= 1;
    	}
    	return res;
}

int main(){
	int a,b,c;
	int n,k;
	cin >> n >> k;
	for(int i=1;i<n;i++){
		cin >> a >> b >> c;
		edges.push_back({a-1,b-1,c});
	}
	for(int i=0;i<n;i++)links.push_back(i);
	sizes.assign(n,1);
	cal();
	long long res = binpow(n,k),aux=0;
	vector<bool> ver(n,0);
	for(int i=0;i<n;i++){
		if(ver[finds(i)])continue;
		aux+=binpow(sizes[finds(i)],k);
		aux%=MODE;
		ver[finds(i)]=1;
	}
	cout << ((res+MODE)-aux)%MODE << endl;
	return 0;
}
