//============================================================================
// Name        : School_home.cpp
// Author      : Lex
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * abstract class "elem"
 */
class elem
{
public:
	virtual int fscanf_el(FILE *f) = 0;
	virtual void show( const char *opening=NULL,
						const char *ending=NULL)=0;
	virtual int free()=0;
	virtual int cmp(elem &e2) = 0;
	int operator  > (elem &e2){ return cmp(e2) >0; }
	int operator >= (elem &e2){ return cmp(e2)>=0; }
	int operator  < (elem &e2){ return cmp(e2) <0; }
	int operator <= (elem &e2){ return cmp(e2)<=0; }
	int operator == (elem &e2){ return cmp(e2)==0; }
	int operator != (elem &e2){ return cmp(e2)!=0; }
//end public
protected:
	void error(char * message){
		cerr << message;
		cout <<"Press any key to end..\n";
		exit(1);
	}//end error

};//end class elem

/*
 * class "usual_elem" == My_Flight_Co
 */

class My_Flight_Co: public elem
{
protected:
	char co_name[33];
	int co_profit;
	double co_raiting;
public:
	My_Flight_Co(){
		co_name[0]='\0';
		co_profit = 0;
		co_raiting = 0.0;
	}

	My_Flight_Co(char *init_co_name, int init_co_profit, double init_co_raiting){
		strcpy(co_name, init_co_name);
		co_profit = init_co_profit;
		co_raiting = init_co_raiting;
	}

	virtual int fscanf_el( FILE *f){
		return fscanf(f, "%s %d %lf", co_name, &co_profit, &co_raiting);
	}

	virtual void show( const char *opening=NULL,
						const char *ending=NULL){
		if( !opening){ opening="";}
		if( !ending) { ending ="";}
		cout << opening;
		if( co_name[0]){
			//cout << co_name << "| " << co_profit << "| "<< co_raiting;
			//cout << ending;
			printf("%-39s %-10d %-5.3lf ", co_name, co_profit, co_raiting);
			printf("%s",ending);

		}//end if
	}//end show()

	virtual int free(){ return co_name[0]=='\0'; }
	virtual int cmp( elem &e2){
		return strcmp(this-> co_name, ( ( My_Flight_Co&)e2).co_name);
	}
};//end class My_Flight_Co

//### main 1###
/*

int main(){
 My_Flight_Co cls_Flights;
 //string src_file = "D:\\C-C++ Eclipse\\airlinesComp.txt" ;
 FILE( *my_file) = fopen("D:\\C-C++ Eclipse\\airlinesComp.txt", "rt");
 if( !my_file){
	 cout << "Cannot open " ;// <<// src_file;
	 cout << "\n== Press any key to exit.";
	 getch();
	 fclose(my_file);
 }
 int i=0;
 while( !( feof( my_file))){
	 if( cls_Flights.fscanf_el(my_file)>0 ){
		i++;
		if( i<=9){ cout << "0"<<i <<": ";}
		if( i>9){cout <<i <<": ";}
		cls_Flights.show(" ", "\n");
	 }
 }//end while
 fclose(my_file);


	return 0;
}//end ### main 1###

*/
