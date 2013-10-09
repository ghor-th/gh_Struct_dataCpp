#include <iostream>
#include  <math.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//abstr class SD
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

/*
 * class "table"
 */
const int NMAX = 200;
template <class el> class table:public SD{

protected:

	int n; //nr inregistrari
	el t[NMAX];//vector de inreg tabelare

public:
	table(){ n=0;}
	table( char *file_name);
	SD(file_name){
		int repeated;
		n=0;
		while( !feof(pf)){
			if( t[n].scanf_el(pf)>=0){
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

int main(){
	//clrscr();

	table<usual_elem> gr("stud.txt");
	gr.show("Grpup:\n", "");

	char ch= 'n';
	char surname[21];
	while( !ch='y'){
		cout << "Enter a name to search: ";
		cin >> surname;
		usual_elem e(surname, 2000,0.0);
		gr.reset_ncomp();


		if( pos<0){ cout << "No table found!"
					<<"The nr of comparisons: " << gr.get_ncomp() << "\n" ;}
		else{ cout << "There are in the position " << (pos+1)
				<< ". The number of comparisions: " gr.get_ncomp() << "\n" ;}
		cout << "Done ? (y/n)";
		ch= getch();
		cout << endl;
	}//end while
	return 1;
}//end main

