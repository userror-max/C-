#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <tuple>
#include <string.h>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
void dataerror(){
	srand(time(0));
	string err[16]={"1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	ofstream ofse("DataErr0r.txt",ios::app);
	while(1){
		string a="color "+err[rand()& 0 + 15)]+err[rand()& 0 + 15)];
		system(a.c_str() );
		cout<<"DataErr0r!!!"<<endl;
		ofse<<"Error!!!";
	}
}
