#include <bits/stdc++.h>

using namespace std;

int main(){
	char suits[4] = {'S','H','D','C'};
	vector<int> cont; // S H D C
	vector<vector<bool>> rel;
	int suit;
	string card;

	int contC=0;

	int res1,res2,aux,mostCards;
	bool stopped;

	while(cin >> card){
	
                if(contC == 0){
                        cont = vector<int>(4,0);
                        rel = vector<vector<bool>>(4,vector<bool>(4,0));
		}

		switch(card[1]){
			case 'S':
				suit=0;
				cont[0]++;
				break;
			case 'H':
				suit=1;
				cont[1]++;
				break;
			case 'D':
				suit=2;
				cont[2]++;
				break;
			case 'C':
				suit=3;
				cont[3]++;
				break;
		}
		
		switch(card[0]){
			case 'A':
				rel[0][suit]=1;
				break;
			case 'K':
				rel[1][suit]=1;
				break;
			case 'Q':
				rel[2][suit]=1;
				break;
			case 'J':
				rel[3][suit]=1;
				break;
		}

		contC++;
		
		if(contC==13){
                        res1=0;
                        for(int i=0;i<4;i++){
                                aux=0;
                                for(int j=0;j<4;j++){
                                        if(rel[i][j]){
						aux++;
						if(i==1 && cont[j]<=1)res1--;
						if(i==2 && cont[j]<=2)res1--;
						if(i==3 && cont[j]<=3)res1--;
					}
                                }
                                res1+=aux*(4-i);
                        }

			res2 = res1;

			for(int j=0;j<4;j++){
				if(cont[j]==2)res2++;
				if(cont[j]<=1)res2+=2;
			}
			if(res1>=16){
				stopped = 1;
				for(int j=0;j<4;j++){
					if(rel[0][j]) stopped&=1;
					else if(rel[1][j] && cont[j]>1)stopped&=1;
					else if(rel[2][j] && cont[j]>2)stopped&=1;
					else stopped&=0;
				}
				if(stopped){
					cout << "BID NO-TRUMP" << endl;
				}
				else{
					if(res2>=14){
						mostCards=0;
						for(int j=1;j<4;j++){
							if(cont[j]>cont[mostCards])mostCards=j;
						}
						cout << "BID " << suits[mostCards] << endl;

					}
					else{
						cout << "PASS" << endl;
					}
				}
			}
			else{
				if(res2>=14){
                                	mostCards=0;
                                        for(int j=1;j<4;j++){
                                        	if(cont[j]>cont[mostCards])mostCards=j;
                                        }
                                        cout << "BID " << suits[mostCards] << endl;
                                }
                                else{
                                	cout << "PASS" << endl;
				}
			}
                        contC=0;
                }

	}
	return 0;
}
