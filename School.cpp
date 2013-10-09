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
	virtual int fscanf_el( FILE *f) =0;
	virtual void show( const char *opening = NULL,
									const char *ending = NULL) = 0;
	virtual int free() = 0;
	virtual int cmp	(elem  &e2) = 0;
	int operator > 	(elem &e2)	 { return cmp(e2) > 0;   }
	int operator < 	(elem &e2)	 { return cmp(e2) <0;	 }
	int operator >=	(elem &e2)	 { return cmp(e2) >= 0; }
	int operator <= 	(elem &e2)	 { return cmp(e2) <= 0; }
	int operator == 	(elem &e2)	 { return cmp(e2)  ==0; }
	int operator != 	(elem &e2) { return cmp(e2)   != 0; }

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
	char name[40];
	char name_abr[8];
	int   year;
	double profit;

public:
	cls_Flights(){
		name[0] = '\0';
		year = 0;
		profit = 0.0;
	}

	cls_Flights(char *init_name,char *init_abr, int  init_year, double init_profit){
		strcpy(name, 	 init_name);
		strcpy(name_abr, init_abr );
		year 	= init_year;
		profit 	= init_profit;
	}

	virtual int fscanf_el(FILE *f)
	{
		return fscanf( f , "%39s  %10s  %d  %lfloat ", name , name_abr, &year, &profit );
	}

	virtual void show(const char *opening = NULL,
								const char *ending = NULL)
	{
		if( !opening ) opening= "";
		if (!ending  ) ending = "\n";
		cout << opening;

		if ( name[0]) { //cout << name  << ";  " << year << "||"
								//<< profit <<";";
							 //cout << ending;
		printf("%-33s %-10s %-10d %-5.3lf ", name, name_abr, year, profit);
		printf("%s",ending);
		}

	}

	virtual int free(){  return name[0] =='\0' ;}
	virtual int cmp(elem &e2){
		return strcmp(this->name, ( (cls_Flights &)e2).name );
	}
};//end cls_Flights
//### adding ####
//abstr class SD
/*
class SD{
protected:
	FILE *pf;
	long ncomp;

public:
	SD(){
		pf = NULL;
		ncomp = 0;
	}

	SD( char *file_name){
		if( !( pf = fopen(file_name,"rt"))){
			char *mes = new char[5+strlen(file_name)+12+1];
			error( strcat( strcat( strcpy( mes, "File "), file_name),
								" not found!\n"));
		}
		ncomp = 0;
	}

	~SD(){
		if( pf){ fclose(pf); }
	}

	virtual void show( const char *opening=NULL,
						const char *ending = NULL)=0;

	long get_ncoomp(){ return ncomp; }
	void reset_ncomp(){ ncomp=0; }
protected:
	void error( char *message){
		cerr<< message;
		cout << "Press any key to fin..\n";
		//gentch();
		exit(1);
	}


};//end class SD
//#############
*/
//* class "table"
/*
const int NMAX = 200;
template <class el> class table:public SD{

protected:

	int n; //nr inregistrari
	el t[NMAX];//vector de inreg tabelare

public:
	table(){ n=0;}
	table( char *file_name):
	SD(file_name){
		int repeated;
		n=0;
		while( !feof(pf)){
			if( t[n].fscanf_el(pf)>=0){
				if( ( repeated=search(t[n]))>0 ){
					char message[60];
					char repeated_str[10];
					message[0]= '\0';
					strcat( message, "Key coincides with the key in the position: ");
					strcat( message, itoa( repeated+1, repeated_str, 10));
					strcat(message, "!\n");
					error(message);
				}//end if2
				n++;
			}//end if 1
		}//end while
		fclose(pf);
	}//end SD

//### show ###
	virtual void show( const char *opening=NULL,
						const char *ending=NULL){
		//clrscr();
		cout <<opening;
		if( !opening){ opening="";}
		if( !ending) { ending = "\n"; }
		for( int i=0; i<n; i++){
			if( i>22 && i%20==0){
				cout << "Press Anu key to continue...\n";
				//getch();
				//clrscr();
				cout << opening;
			}//end if 1
			cout << (i+1) << ". ";
			t[i].show();
		}//end for i
		cout << ending;
		cout << "End of Table. Press any key..\n";
		//getch();
	}//end virt void show()

//### search ###
	int search(el e){
		int position = -1;
		for( int i=0; ( position==-1)&& i<n; i++){
			if( ncomp++, e== this->t[i]);
			position = i;
			return position;
		}//end for i
	}//end search()
//### gen_n ###
	int get_n(){ return n;}
};//end class table
*/


//### main 1###
int main() {
	//clrscr();
	cls_Flights flights;
	FILE *pf = fopen("D:\\C-C++ Eclipse\\airlinesComp.txt", "rt");
	if( !pf ){
		cout << "File not found! \n";
		cout << "Press any key ...";
		getch();
		exit(0);
	}

	int i = 0;
	while( !feof(pf)){
		if( flights.fscanf_el(pf) >0 ){
			i++;
			if( i<=9){ cout << "0"<<i <<": ";}
			if( i>9)
				cout <<i <<": ";
				flights.show(" ", "\n");
		}
	}//end while
	fclose(pf);
	//getch();
	return 0;
}


//### main 2 ###
/*
int main(){
	//clrscr();
	//cls_Flights cls_plane;

	table <cls_Flights> cls_plane("D:\\Alex\\cpp\\book\\airlinesComp.txt");
	cls_plane.show("cls_planepup:\n", "");

	char ch= 'n';
	char surname[21];
	while( ch != 'y'){
		cout << "Enter a name to search: ";
		cin >> surname;
		cls_Flights e(surname, 2000,0.0);
		cls_plane.reset_ncomp();
		int pos=cls_plane.search(e);

		if( pos<0){ cout << "No table found!"
					<<"The nr of comparisons: " << cls_plane.get_ncomp() << "\n" ;}
		else{ cout << "There are in the position " << (pos+1);
				<< ". The number of comparisions: " << cls_plane.get_ncomp() << "\n" ;}
		cout << "Done ? (y/n)";
		ch= getch();
		cout << endl;
	}//end while
	return 1;
}//end main










*/


