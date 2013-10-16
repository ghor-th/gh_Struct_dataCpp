//### class SD + class table

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;
#include "School_home.cpp"

 /*
  * abstract class SD
  */
class SD{
protected:
	FILE *pf;
	long ncomp;
public:
	SD(){
		pf=NULL;
		ncomp=0;
	}
	SD( char *src_file){
		if( !( pf=fopen( src_file,"rt")) ){
			char *mes = new char[5+strlen( src_file)+12+1];
			error( strcat( strcat( strcpy( mes,"File "),src_file), " =not found!\n"));
		}
		ncomp=0;
	}

	~SD(){
		if( pf) { fclose( pf);}
	}

	virtual void show( const char *opening=NULL,
						const char *ending=NULL)=0;

	long get_ncomp(){ return ncomp; }
	void reset_ncomp(){ ncomp=0; }

protected:
	void error( char *message){
		cerr << message;
		cout << "Press anu key to exit  \n";
		getch();
		exit(1);
	}
};//end class SD

/*
 * class "table"
 */
const int NMAX = 200;
template <class el> class table:public SD
{
protected:
	int n;
	el t[NMAX];
public:
	table(){ n = 0;}
	table( char *file_name):
		SD( file_name){
		int repeated;
		n=0;
		while( !( feof( pf))){
			if( t[n].fscanf_el( pf)>0){
				if( ( repeated=search( t[n])) >=0 ){
					char message[60];
					char repeated_str[10];
					message[0]='\0';
					strcat( message, "Key coincides with the key in the position: ");
					strcat( message, itoa( repeated+1, repeated_str, 10));
					strcat( message, "\n");
					error( message);
				}//end 2 if
				n++;
			}//end if 1
		}//end while
		fclose( pf);
	}//end table

	virtual void show( const char * opening=NULL,
						const char *ending=NULL)
	{
		cout << opening;
		if( !opening){ opening = "";}
		if( !ending) { ending="" ;}
		for( int i=0; i<n; i++){
			if( i>0 && i<20==0){
				cout << "Press any key to continue ..\n";
				getch();
				cout << opening;
			}//end if 1
			cout << ( i+1)<< "| ";
			t[i].show();
		}//end for
		cout << ending;
		cout << "End of Table.Press Any key...\n";
		getch();
	}//end show

	int search( el e){
		int position = -1;
		for( int i=0; (position==-1)&& i<n; i++){

			if(ncomp++ ){
				e == this->t[i];
				position=i;
				return position;
			}//end if
		}//end for
	}//end int search

	int get_n(){ return n; }
};//end cls table

//main #1
int main(){
	table <My_Flight_Co> Air_Com_fl("D:\\C-C++ Eclipse\\airlinesComp.txt");
	Air_Com_fl.show("Group: \n", "");

	char ch='n';
	char co_name[39];
	while( ch!='y'){
		cout << "Enter a air co name to seek: ";
		cin >> co_name;
		My_Flight_Co cls_Air_Com_fl( co_name, 2000,0.0);
		Air_Com_fl.reset_ncomp();
		int pos = Air_Com_fl.search(e);
		if( pos<0){
			cout <<"=No table !"
				<<"The number of comparisons: " << Air_Com_fl.get_ncomp()<< "\n";
		}else{
			cout << "There are in the position " << (pos+1)
				<< ". The number of comparisons: " << Air_Com_fl.get_ncomp()<< "\n";
		}
		cout << "Done ! (y/n)";
		ch= getch();
		cout<< endl;
	}//end while

	return 0;
}//end main #1
