#include <bits/stdc++.h>

#define M 280

using namespace std;

int days[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
int lim[12] = {21,20,21,21,22,22,23,22,24,24,23,23};
string bef[12] ={"capricorn","aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius"};

int main(){
	int n,month,day,year,t;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		month = atoi(s.substr(0,2).c_str());
		day = atoi(s.substr(2,2).c_str());
		year = atoi(s.substr(4).c_str());
		if(month>3)year++;
		t=0;
		if(12-month<9){
			t+=days[12]-days[month-1];
			t+=days[8-(12-month)];
		}
		else{
			t+=days[month+8]-days[month-1];
		}
		if(year%4==0 && (5<month || month<3)){
			if(year%100==0 && year%400==0)
				t++;
			if(year%100!=0)
				t++;
		}
		month=(month+9)%12;
		if(month==0)month=12;
		int aux = days[month]-days[month-1];
		if(day+(280-t)>aux){
			month++;
			if(month>12){
				month=1;
				year++;
			}
			day+=(280-t);
			day%=aux;
		}
		else day+=(280-t);
		string zod;
		if(lim[month-1]>day){
			zod=bef[month-1];
		}
		else{
			zod=bef[month%12];
		}
		cout << i << " ";
		if(month<10)cout << 0;
		cout<< month << "/";
		if(day<10)cout << 0;
		cout << day <<"/";
		cout << year << " " << zod<< endl;
	}
	return 0;
}
