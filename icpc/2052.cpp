#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int x,y,res;
	while(t--){
		scanf("%d %d",&x,&y);
		//cin >> x >> y;
		if(y!=x && y!=(x-2))printf("No Number\n");//cout << "No Number"<<endl;
		else{
			res = x+y;
			if(y&1)res--;
			printf("%d\n",res);
			//cout << res << endl;
		}
	}
	return 0;
}
