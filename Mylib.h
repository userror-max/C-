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
#define Keydown GetAsyncKeyState

using namespace std;

void print(string text,int speed){
	for (size_t i = 0; i < text.length(); ++i){	
		cout<<text[i];
		Sleep(speed);
	}
	cout<<endl;
}

struct File{//�����ļ��� 
	struct Deleta{//ɾ�� 
		int r(string del){//����ɾ�� 
			string de="del /p "+del;
			system(de.c_str());
			ifstream ifs(del);
			if(ifs.is_open()){
				ifs.close();
				return 0;
			}
			else{
				return 1;
			} 
		}
		void f(string del){//ǿ��ɾ�� 
			string de="del /f /p "+del;
			system(de.c_str());
		}
	}deleta;
	
	struct Error{//����(?) 
		void c(int a){//��ò��� 
			ofstream ok("file{error}.ini",ios::app);
			a*=10000;
			while(a>0){
				ok<<"err";
				a--;
			}
		}
		void dataerror(int ap){
			srand(time(0));
			string err[16]={"1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
			string ero(10000,'Error'); 
			ofstream ofse("DataErr0r.txt",ios::app);
			while(--ap){
				string a="color "+err[rand()& 0 + 15]+err[rand()& 0 + 15];
				system(a.c_str() );
				cout<<"DataErr0r!!!"<<endl;
				ofse<<ero;
			}
		}
	}error;		
	
}file;

struct PhigrOS{// Phigros(��)
	int work_out(){//����� 
		srand(time(0));
		int file_time=1,file_name=0;
		
		ifstream ifs("phigros.ini");
		if(ifs.is_open()){
			ifs>>file_time;
			ifs>>file_name;
		}
		ofstream of("phigros.ini");
		of<<file_time+1<<endl
		  <<file_name<<endl;
		
	
		system("cls");
	    long long total, z;
	    cout<<"���Ѿ�����"<<file_time<<"��"<<endl;
		cout<<"���Ѿ�������"<<file_name<<"���ļ�" <<endl<<endl;
		
	    cout<<"����������:";
	    cin >> total ;
	    cout<<"������Ŀ�����:";
		cin>> z;
	
	    if (total <= 0) {
	        cout << "û�з�����~" << endl;
	        return 0;
	    }
	
	    vector<tuple<long long, long long, long long>> solutions;
	
	    for (long long g = 0; g <= total && solutions.size() < 100; g++) {
	        double p_approx = (static_cast<double>(z) * total - static_cast<double>(g) * 650000.0) / 1000000.0;
	        long long p_center = static_cast<long long>(round(p_approx));
		
	        for (long long offset = -1; offset <= 1; offset++) {
	            long long p = p_center + offset;
	            if (p < 0 || p > total - g) continue;
	
	            long long m = total - p - g;
	            long long numerator = p * 1000000LL + g * 650000LL;
	            long long x_val = (numerator + total / 2) / total; // ��������
	
	            if (x_val == z) {
	                solutions.push_back(make_tuple(p, g, m));
	                if (solutions.size() >= 100) break;
	            }
	        }
	    }
	
	    if (solutions.empty()) {
	        cout << "û�з�����~" << endl;
	    } else {
	    	ofstream ofs("phigros_file_"+to_string(file_time+1)+".txt",ios::app);
		    cout<<"�ҵ���"<<solutions.size()<<"������"<<endl;
		    file_name+=1;
		    of<<file_time+1<<endl
		  	  <<file_name<<endl;
			  		  
		    int i=0;
		    for (const auto& sol : solutions) {
		        cout << "perfect: " << get<0>(sol) << ", good: " << get<1>(sol) << ", miss: " << get<2>(sol) << endl;
		    	ofs <<"���� "<< (i + 1) <<endl
		            <<"perfect: "<<get<0>(sol)<<endl
		            <<"good: "<<get<1>(sol)<<endl
		            <<"miss: "<<get<2>(sol)<<endl<<endl;
			            
		        i+=1;
		    }
		}
		system("pause");
	} 
}Phigros;

