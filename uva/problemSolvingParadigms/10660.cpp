#include <bits/stdc++.h>

using namespace std;

int fd(int a,int b){
	return abs((a/5)-(b/5))+abs((a%5)-(b%5));
}

int main(){

	int t,n,r,c,v,dist,tmp,sumDist,minSumDist;
	vector<int> area,sol;
	cin >> t;

	while(t--){
		cin >> n;
		
		area.assign(25,0);

		while(n--){
			cin >> r >> c >> v;
			area[(r*5)+c]=v;
		}

		minSumDist=100000;

		for(int o1=0;o1<21;o1++){
			for(int o2=o1+1;o2<22;o2++){
				for(int o3=o2+1;o3<23;o3++){
					for(int o4=o3+1;o4<24;o4++){
						for(int o5=o4+1;o5<25;o5++){

							sumDist=0;
							for(int i=0;i<25;i++){
								if(area[i]>0){
									dist=min(min(fd(i,o1),fd(i,o2)),min(fd(i,o4),fd(i,o3)));
									dist=min(dist,fd(i,o5));
									sumDist+=(dist*area[i]);
								}
							}
							
							if(minSumDist>sumDist){
								minSumDist=sumDist;
								sol = {o1,o2,o3,o4,o5};
							}
						}
					}
				}
			}
		}

		for(int i=0;i<5;i++){
			if(i!=0) cout << " ";
			cout << sol[i];
		}
		cout << endl;

	}
	return 0;
}
