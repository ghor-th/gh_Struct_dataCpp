//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include  <math.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
//================

class elem{
public:
	virtual int fscanf_el( FILE *f) =0;
	virtual void show( const char *opening = NULL,
					const char *ending = NULL) = 0;
	virtual int free() = 0;
	virtual int cmp (elem& e2) = 0;
	int operator >  (elem& e2)	 { return cmp(e2) >  0;}
	int operator <  (elem& e2)	 { return cmp(e2) <  0;}
	int operator >= (elem& e2)	 { return cmp(e2) >= 0;}
	int operator <= (elem& e2)	 { return cmp(e2) <= 0;}
	int operator == (elem& e2)	 { return cmp(e2) == 0;}
	int operator != (elem& e2)	 { return cmp(e2) != 0;}

	~elem(){};
protected:
	void error(char *message){
		cerr << message;
		cout<< "Press any key..";
		getch();
		exit(1);
	}

}; //end cls elem
//===================


class cls_Flights : public elem{
protected:
	char name[30];
	int   year;
	double profit;

public:
	cls_Flights(){
		name[0] = '\0';
		year = 0;
		profit = 0.0;
	}

	cls_Flights(char *init_name, int  init_year, double init_profit){
		strcpy(name, init_name);
		year = init_year;
		profit = init_profit;
	}

	int fscanf_el(FILE *fp){
		return fscanf( fp , "%s %d  %lf", name , &year, &profit );
	}

	void show(const char *opening = NULL,
								const char *ending = NULL)
	{
		if( !opening ) opening= "";
		if (!ending  ) ending = "\n";
		cout << opening;
		if (name[0]){
			cout << name << "; " << year << "; "
									<< profit <<"; ";
		}
		cout << ending;
	}

	virtual int free(){  return name[0] =='\0' ;}
	virtual int cmp(elem &e2){
		return strcmp(this->name, ( (cls_Flights &)e2).name );
	}

};//end cls_Flights
//========main================
/*
int main() {
	//clrscr();
	cls_Flights clFlight;
	FILE *pf = fopen("D:\\Alex\\cpp\\book\\air_comp_5.txt", "rt");
	if( !pf ){
		cout << "File not found! \n";
		cout << "Press any key ...";
		getch();
		exit(0);
	}

	int i = 0;
	while( !feof(pf)){
		if( clFlight.fscanf_el(pf) > 0 ){
			i++;
			cout <<i <<"   ";
			clFlight.show("", "\n");
		}

	}//end while
	fclose(pf);
	//getch();
	return 0;
}
*/
