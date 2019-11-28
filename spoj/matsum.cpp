#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> BIT,mat,aux;
int N;

void update(int x,int y,long long val){
	int auxY=y;
	for(;x<=N;x+=(x&-x)){
		for(;y<=N;y+=(y&-y)){
			BIT[x][y] += val;
		}
		y=auxY;
	}
}

long long getSum(int x,int y){
	long long res = 0;
	int auxY = y;
	for(;x>0;x-=(x&-x)){
		for(;y>0;y-=(y&-y)){
			res+=BIT[x][y];
		}
		y=auxY;
	}
	return res;
}

void constructAux(){
	aux.assign(N+1,vector<long long>(N+1,0));
	for(int j=1;j<=N;j++){
		for(int i=1;i<=N;i++){
			aux[i][j]=mat[N-j][i-1];
		}
	}
}

void create(){
	constructAux();
	BIT.assign(N+1,vector<long long>(N+1,0));
	for(int j=1;j<=N;j++){
		for(int i=1;i<=N;i++){
			long long v1 = getSum(i,j);
			long long v2 = getSum(i,j-1);
			long long v3 = getSum(i-1,j-1);
			long long v4 = getSum(i-1,j);
			update(i,j,aux[i][j]-(v1-v2-v4+v3));
		}
	}
}

long long query(int x1,int y1,int x2, int y2){
	long long ans = getSum(x2,y2)-getSum(x2,y1-1)-getSum(x1-1,y2)+getSum(x1-1,y1-1);
	return ans;
}


int main(){
	int t,a,b,c,d;
	long long v;
	char op[3];
	scanf("%d",&t);
	//cin >> t;
	while(t--){
		scanf("%d",&N);
		//cin >> N;
		mat.assign(N,vector<long long>(N,0));
		//create();
		BIT.assign(N+1,vector<long long>(N+1,0));
		while(scanf("%3s",op)){
			if(op[0] == 'E')break;
			if(op[1] == 'E'){
				scanf("%d %d %lld",&a,&b,&v);
				//cin >> a >> b >> v;
				update(a+1,b+1,v-mat[a][b]);
				mat[a][b]=v;
			}
			if(op[1] == 'U'){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				//cin >> a >> b >> c >> d;
				printf("%lld\n",query(a+1,b+1,c+1,d+1));
			}
		}
		cout << endl;
	}
	return 0;
}
