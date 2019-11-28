#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,d,e;
	int pos1,pos2,min1,min2;
	int res;
	while(cin >> a >> b >> c >> d >> e){
		if((a+b+c+d+e)==0)break;

		pos1=pos2=0;
		min1=min2=1000;

		if(a>d){
			if(min1>(a-d)){
				min1=a-d;
				pos1=1;
			}
		}
		if(b>d){
			if(min1>(b-d)){
				min1=b-d;
				pos1=2;
			}
		}
		if(c>d){
			if(min1>(c-d)){
				min1=c-d;
				pos1=3;
			}
		}

		if(a>e){
			if(min2>(a-e) && pos1!=1){
				min2=a-e;
				pos2=1;
			}
		}
		if(b>e){
			if(min2>(b-e) && pos1!=2){
				min2=b-e;
				pos2=2;
			}
		}
		if(c>e){
			if(min2>(c-e) && pos1!=3){
				min2=c-e;
				pos2=3;
			}
		}

		if(pos1!=0 && pos2!=0) cout << -1 << endl;
		else{
			if((pos1+pos2) == 0)
				res = 1;
			if((pos1+pos2) == 1)
				res = max(b,c);
			if((pos1+pos2) == 2)
				res = max(a,c);
			if((pos1+pos2) == 3)
				res = max(a,b);

			while(res==a || res==b || res==c || res==d || res==e){
				res++;
			}
			if(res>52) cout<<-1<<endl;
			else cout << res << endl;
		}
	}
	return 0;
}
