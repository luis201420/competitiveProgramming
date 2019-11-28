#include <bits/stdc++.h>

using namespace std;

vector<int> cont(10,0);

int month,day,hour,minu;

bool cminu(){
	int d1,d2;
	for(int i=59;i>=0;i--){
                d1=i%10;
                d2=i/10;
                if(d1==d2){
                        if(cont[d1]>1){
                                minu=i;
                                cont[d1]-=2;
				return true;
                        }
                }
                else if(cont[d1] && cont[d2]){
                        minu=i;
                        cont[d1]--;
                        cont[d2]--;
			return true;
                }
        }
	return false;
}

bool chour(){
	int d1,d2;
	for(int i=23;i>=0;i--){
                d1=i%10;
                d2=i/10;
                if(d1==d2){
                        if(cont[d1]>1){
                                hour=i;
                                cont[d1]-=2;
				if(cminu())return true;
				cont[d1]+=2;
                        }
                }
                else if(cont[d1] && cont[d2]){
                        hour=i;
                        cont[d1]--;
                        cont[d2]--;
			if(cminu())return true;
			cont[d1]++;
			cont[d2]++;
                }
        }
	return false;
}

bool cday(int m){
	int d1,d2,i;
	if(m==2){i=28;}
        else if(m<=7){
                if(m&1)i=31;
                else i=30;
        }
        else{
                if(m&1)i=30;
                else i=31;
        }

        for(;i>0;i--){
                d1=i%10;
                d2=i/10;
                if(d1==d2){
                        if(cont[d1]>1){
                                day=i;
                                cont[d1]-=2;
				if(chour())return true;
				cont[d1]+=2;
                        }
                }
                else if(cont[d1] && cont[d2]){
                        day=i;
                        cont[d1]--;
                        cont[d2]--;
			if(chour())return true;
			cont[d1]++;
			cont[d2]++;
                }
        }
	return false;
}

bool cmonth(){
	int d1,d2,i;
        for(i=12;i>0;i--){
                d1=i%10;
                d2=i/10;
                if(d1==d2){
                        if(cont[d1]>1){
                                month=i;
                                cont[d1]-=2;
				if(cday(i))return true;
				cont[d1]+=2;
                        }
                }
                else if(cont[d1] && cont[d2]){
                        month=i;
                        cont[d1]--;
                        cont[d2]--;
			if(cday(i))return true;
                        cont[d1]++;
			cont[d2]++;
                }
        }
	return false;
}

int main(){
	string s;
	cin >> s;
	int n;

	for(unsigned i=0;i<s.size();i+=2){
		cont[s[i]-'0']++;
	}

	month=day=hour=minu=-1;
	
	//cmonth();

	if(!cmonth()){
		cout << 0;
	}
	else{
		if(month<10)cout << 0;
		cout << month << "/";
       		if(day<10)cout << 0;
		cout<< day << " " ;
		if(hour<10)cout << 0;
		cout << hour << ":";
		if(minu<10)cout << 0;
		cout << minu;
	}
	return 0;
}
