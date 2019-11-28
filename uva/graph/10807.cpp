#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u,v,w;
};

vector<vector<int>> link,sizeT;
vector<Edge> edges;

int findT(int x,int c){
	if(x == link[c][x])return x;
	return link[c][x] = findT(link[c][x],c);
}

bool same(int a,int b,int c){
	return findT(a,c)==findT(b,c);
}

void unite(int a,int b,int c){
	a=findT(a,c);
	b=findT(b,c);
	if(sizeT[c][a]<sizeT[c][b])swap(a,b);
	link[c][b]=a;
	sizeT[c][a]+=sizeT[c][b];
}

bool myComp(const Edge & e1,const Edge & e2){
	return e1.w<e2.w;
}

int n,m;
int cont1,cont2;
bool ver;
int ans;

void solution(int i){
	if(i==m){
		if((sizeT[0][findT(0,0)]==n) && (sizeT[1][findT(0,1)]==n)){
			//cerr << "3 ### " << cont1 << " " << cont2  << endl;
			ver = 1;
			if((cont1+cont2)<ans) ans=(cont1+cont2);
		}
	       	return;
	}
	if((sizeT[0][findT(0,0)]==n) && (sizeT[1][findT(0,1)]==n)){
		//cerr << "3 --- " << cont1 << " " << cont2 << endl;
		ver = 1;
		if((cont1+cont2)<ans) ans=(cont1+cont2);
		return;
	}
	vector<int> linkA,sizeA;
	int aux1,aux2;
	int u1,u2,u3;
	u1=edges[i].u;u2=edges[i].v;u3=edges[i].w;
	
	if(!same(u1,u2,0) || !same(u1,u2,1)){
	if(!same(u1,u2,0)){
		//cerr << "1 --- " << i << endl;
		linkA = link[0];sizeA = sizeT[0];
		unite(u1,u2,0);
		aux1=cont1;
		cont1+=u3;
		solution(i+1);
		cont1=aux1;
		link[0]=linkA;sizeT[0]=sizeA;
	}
	if(!same(u1,u2,1)){
		//cerr << "2 --- " << i << endl;
		linkA = link[1];sizeA = sizeT[1];
		unite(u1,u2,1);
		aux2=cont2;
		cont2+=u3;
		solution(i+1);
		cont2=aux2;
		link[1]=linkA;sizeT[1]=sizeA;
	}
	//cerr << "p" << endl;
	}
	else solution(i+1);
}

int main(){
	int c1,c2,c3;
	while(cin >> n){
		if(n==0)break;
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> c1 >> c2 >> c3;
			edges.push_back({c1-1,c2-1,c3});
		}
		sizeT.assign(2,vector<int>());
		link.assign(2,vector<int>());
		sizeT[0].assign(n,1);
		sizeT[1]=sizeT[0];
		for(int i=0;i<n;i++)link[0].push_back(i);
		link[1]=link[0];
		sort(edges.begin(),edges.end(),myComp);
		ver=0;cont1=cont2=0;
		ans=1e9;	
		solution(0);
		if(ver) cout<< ans << endl;
		else cout << "No way!" << endl;
		link.clear();
		edges.clear();
	}
	return 0;
}
