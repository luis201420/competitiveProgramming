#include <bits/stdc++.h>

using namespace std;

int sum(int n){
        return (n*(n+1))/2;
}

int sumI(int a,int b){
        return sum(b)-sum(a-1);
}

int main(){
        int dif,a,b,c1,c2;
        cin >> dif >> a >> b;
        c1=3+dif;
        c2=3;
        for(int i=0;i<1000;i++){
        	if((sumI(4,c1+i)+sumI(3,c2+i))==(a+b)){
                	cout << (sumI(3,c2+i)-b) << endl;
                        break;
                }
        }
        return 0;
}

