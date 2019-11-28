#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	
	cin >> n;

	int cont = 1;
	bool ver = 0;

	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cont++;
			if((int(sqrt(i))*int(sqrt(i)))==i){
				cont--;
				//cerr << "-" << i << endl;
				ver=1;
				//continue;
			}
			else{
				for(int j=2;j<=sqrt(i);j++){
					if(i%j==0){
						if((int(sqrt(j))*int(sqrt(j)))==j){
							//cerr << "+" << i << endl;
							cont--;
							break;
						}
						if(((i/j)!=j) && ((int(sqrt(i/j))*int(sqrt(i/j)))==(i/j))){
       		                                 	//cerr << "+" << i << endl;
							cont--;
        	                                       	break;
                	                        }
					}
				}
			}
			if(i!=(n/i)){
				cont++;
				if((int(sqrt(n/i))*int(sqrt(n/i)))==(n/i)){
                                	cont--;
					//cerr << "-" << n/i << endl;
					ver=1;
                                	//continue;
                        	}
				else{
					for(int j=2;j<=sqrt(n/i);j++){
						if((n/i)%j==0){
                        		       	 	if((int(sqrt(j))*int(sqrt(j)))==j){
								//cerr << "+" << n/i << endl;
								cont--;
                               	        			break;
                               		 		}
							if(((n/i)/j != j)&&((int(sqrt((n/i)/j))*int(sqrt((n/i)/j)))==((n/i)/j))){
								//cerr << "+" << (n/i) << endl;
								cont--;
                                               			break;
                                        		}
						}
                        		}
				}
			}
		}
	}

	if(ver)cont--;
	else{
		if((int(sqrt(n))*int(sqrt(n)))==n)cont--;
	}
	cout << cont;
	return 0;
}
